import pygame

from ant import *
from room import *
from lemin import *
from parser import *

lem = Lemin()
if not parse_input(lem):
    exit()

rooms = lem.rooms
pygame.init()

WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
GRAY = (125, 125, 125)
LIGHT_BLUE = (64, 128, 255)
GREEN = (0, 200, 64)
YELLOW = (225, 225, 0)
PINK = (230, 50, 230)
sc = pygame.display.set_mode((1280, 720))
bg = pygame.image.load('visualize/models/bg3.jpg')
pepe_old = pygame.image.load('visualize/models/pepe.png')
pygame.display.set_caption('Lem-in')
clock = pygame.time.Clock()

def draw_rooms():
    sc.blit(bg, (0, 0))
    for room in rooms:
        pygame.draw.circle(sc, LIGHT_BLUE, rooms[room].coord(), rad)
        for lnk in rooms[room].links:
            pygame.draw.line(sc, WHITE, rooms[room].coord(), rooms[lnk].coord(), 2)

    pygame.draw.circle(sc, GREEN, lem.st_coord(), rad)
    pygame.draw.circle(sc, PINK, lem.en_coord(), rad)

def move(flag):
    for room in rooms:
        if flag == 'UP':
            rooms[room].y -= 50
        elif flag == 'DOWN':
            rooms[room].y += 50
        elif flag == 'RIGHT':
            rooms[room].x += 50
        elif flag == 'LEFT':
            rooms[room].x -= 50
    draw_rooms()
    pygame.display.update()

def scale(flag):
    for room in rooms:
        if flag == 'x_up':
            x = rooms[room].x
            x = int((x - 640) * 1.15 + 640)
            rooms[room].x = x
        elif flag == 'x_down':
            x = rooms[room].x
            x = int((x - 640) / 1.15 + 640)
            rooms[room].x = x
        elif flag == 'y_up':
            y = rooms[room].y
            y = int((y - 360) * 1.15 + 360)
            rooms[room].y = y
        elif flag == 'y_down':
            y = rooms[room].y
            y = int((y - 360) / 1.15 + 360)
            rooms[room].y = y
    draw_rooms()
    pygame.display.update()

def print_text(message, x, y, size):
    font_type = pygame.font.Font("visualize/Comic.ttf", size)
    text = font_type.render(message, True, (255, 255, 255))
    sc.blit(text, (x, y))
    pygame.display.update()

def draw_ants():
    draw_rooms()
    for ant in ants_in:
        sc.blit(pepe, (lem.ants[ant].x - rad * 2, lem.ants[ant].y - rad * 2))
    pygame.display.update()

def move_ants():
    ret = 0
    for ant in ants_in:
        x, y = lem.ants[ant].coord()
        e_x, e_y = lem.en_coord()
        if x == e_x and y == e_y:
            ants_in.remove(ant)
        if lem.ants[ant].x != lem.ants[ant].dx or lem.ants[ant].y != lem.ants[ant].dy:
            ret = 1
            lem.ants[ant].move_to(vel)
    return ret

def get_ants():
    curr = lem.solution.pop(0).split()
    for ant in curr:
        parts = ant.split('-')
        ant_i = parts[0][1:]
        room = parts[1]
        x, y = lem.ants[ant_i].coord()
        s_x, s_y = lem.st_coord()
        if x == s_x and y == s_y:
            ants_in.append(ant_i)
        lem.ants[ant_i].new_dest(lem.rooms[room])

def create_ants():
    for ind in range(lem.ant_cnt + 1):
        (st_x, st_y) = lem.st_coord()
        lem.ants[str(ind)] = Ant(st_x, st_y)

def paused():
    print_text("Lem-in paused", 550, 15, 20)
    pause = True
    while pause:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                exit()
            elif event.type == pygame.KEYDOWN and event.key == pygame.K_SPACE:
                pause = False

def endgame():
    sc.blit(bg, (0, 0))
    print_text("thank you for your time!", 400, 300, 30)
    print_text("made for 21 community.", 400, 400, 20)
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT: exit()
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RETURN: exit()

def pepedance():
    print_text("press enter to free pepega...", 550, 700, 20)
    button = 1
    while button:
        for event in pygame.event.get():
            if event.type == pygame.QUIT: exit()
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RETURN:
                    button = 0
    sc.blit(bg, (0, 0))
    pepe = pygame.transform.scale(pepe_old, (rad * 8, rad * 8))
    sc.blit(bg, (0, 0))
    x = 640
    y = 360
    vel_x = 3
    vel_y = 2
    pygame.display.update()
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT: exit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RETURN: endgame()
                elif event.key == pygame.K_UP:
                    if vel_y * 1.5 < 5:
                        vel_y = vel_y * 1.5
                elif event.key == pygame.K_DOWN: 
                    if vel_y > 0.2:
                        vel_y = vel_y / 1.5
                elif event.key == pygame.K_RIGHT:
                    if vel_x * 1.5 < 5:
                        vel_x = vel_x * 1.5
                elif event.key == pygame.K_LEFT:
                    if vel_x > 0.2:
                        vel_x = vel_x / 1.5
        sc.blit(pepe, (x, y))
        pygame.display.update()
        clock.tick(30)
        if x + vel_x < -rad * 4 or x + vel_x > 1280 - rad * 4:
            vel_x *= -1
        if y + vel_y < -rad * 4 or y + vel_y > 720 - rad * 4:
            vel_y *= -1
        x += vel_x
        y += vel_y
    

def part3():
    global ants_in
    global pepe
    global vel
    vel = 0.1
    create_ants()
    pepe = pygame.transform.scale(pepe_old, (rad * 4, rad * 4))
    ants_in = list()
    get_ants()
    draw_ants()
    moved = 0
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT: exit()
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_UP and vel < 0.75:
                    vel += 0.05
                elif event.key == pygame.K_DOWN and vel > 0.1:
                    vel -= 0.05
                elif event.key == pygame.K_SPACE: paused()
        moved = move_ants()
        draw_ants()
        clock.tick(60)
        if moved == 0 and len(lem.solution) != 0:
            get_ants()
            draw_ants()
        if moved == 0 and len(ants_in) == 0:
            pepedance()

def part2():
    global rad
    rad = 15
    draw_rooms()
    pygame.display.update()
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT: exit()
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RETURN:
                    part3()
                elif (event.key == pygame.K_UP or event.key == pygame.K_RIGHT) and event.mod == pygame.KMOD_LALT:
                    if rad < 100:
                        rad = int(rad * 1.25)
                        draw_rooms()
                        pygame.display.update()
                elif (event.key == pygame.K_DOWN or event.key == pygame.K_LEFT) and event.mod == pygame.KMOD_LALT:
                    if rad > 5:
                        rad = int(rad / 1.25)
                        draw_rooms()
                        pygame.display.update()
                elif event.key == pygame.K_UP and event.mod == pygame.KMOD_LSHIFT: scale('y_up')
                elif event.key == pygame.K_DOWN and event.mod == pygame.KMOD_LSHIFT: scale('y_down')
                elif event.key == pygame.K_RIGHT and event.mod == pygame.KMOD_LSHIFT: scale('x_up')
                elif event.key == pygame.K_LEFT and event.mod == pygame.KMOD_LSHIFT: scale('x_down')
                elif event.key == pygame.K_UP: move("UP")
                elif event.key == pygame.K_DOWN: move("DOWN")
                elif event.key == pygame.K_RIGHT: move("RIGHT")
                elif event.key == pygame.K_LEFT: move("LEFT")
            clock.tick(30)

def part1():
    x = 350
    y = 300
    sc.blit(bg, (0, 0))
    print_text("instructions:", x, y, 30)
    print_text("i. use arrows to move graph.", x, y + 50, 20)
    print_text("ii. hold left shift to scale graph. you better do it in the middle.", x, y + 75, 20)
    print_text("iii. hold left alt to scale rooms size (it will affect ants size).", x, y + 100, 20)
    print_text("iv. when you're ready press enter to run algorithm.", x, y + 125, 20)
    print_text("press enter to continue...", x, y + 175, 10)
    pygame.display.update()
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT: exit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RETURN: 
                    sc.fill((0, 0, 0))
                    part2()
        clock.tick(30)

def start_script():
    sc.blit(bg, (0, 0))
    pygame.display.update()
    print_text("hello! this is ifran's and jkrypto's lem-in project", 100, 350, 35)
    print_text("press enter to continue...", 100, 400, 20)
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT: exit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RETURN: part1()
        clock.tick(30)

start_script()
