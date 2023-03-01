import pygame

from ant import *
from room import *
from parser import *

"""
def add_room(room):
    name = room[0]
    x = int(room[1]) * 10 + 640
    y = int(room[2]) * 20 + 360
    rooms[name] = Room(x, y)

def add_start(room):
    global start
    name = room[0]
    add_room(room)
    start = rooms[name]

def add_end(room):
    global end
    name = room[0]
    add_room(room)
    end = rooms[name]

def create_ants(cnt):
    for ind in range(cnt):
        ants[str(ind)] = Ant(start.coord())

def parse_input():
    readed = 0

    # Считываем количество муравьёв
    ant_cnt = 0
    inp = input()
    while inp[0] == '#':
        inp = input()
    if inp.isdigit():
        ant_cnt = int(inp)

    # Считываем комнаты
    while True:
        try:
            inp = input()
            if inp:
                if inp == '##start':
                    while inp[0] is '#':
                        inp = input()
                    add_start(inp.split(' '))
                elif inp == "##end":
                    while inp[0] is '#':
                        inp = input()
                    add_end(inp.split(' '))
                elif inp[0] == '#':
                    continue
                elif inp[0] == 'L':
                    solution.append(inp)
                elif ' ' in inp:
                    add_room(inp.split(' '))
                elif '-' in inp:
                    (room1, room2) = inp.split('-')
                    rooms[room1].add_link(room2)
            readed += 1
        except EOFError:
            return readed
"""

lem = Lemin()
if not parse_input(lem):
    exit()

pygame.init()

WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
GRAY = (125, 125, 125)
LIGHT_BLUE = (64, 128, 255)
GREEN = (0, 200, 64)
YELLOW = (225, 225, 0)
PINK = (230, 50, 230)
sc = pygame.display.set_mode((1280, 720))
bg = pygame.image.load('visualize/bg3.jpg')
pepe_old = pygame.image.load('visualize/pepe.png')
pygame.display.set_caption('Lem-in')
clock = pygame.time.Clock()

def draw_rooms():
    sc.blit(bg, (0, 0))
    #sc.fill((0, 0, 0))
    for room in rooms:
        pygame.draw.circle(sc, LIGHT_BLUE, rooms[room].coord(), rad)
        for lnk in rooms[room].links:
            pygame.draw.line(sc, WHITE, rooms[room].coord(), rooms[lnk].coord())
    pygame.draw.circle(sc, GREEN, start.coord(), rad)
    pygame.draw.circle(sc, PINK, end.coord(), rad)
    pygame.display.update()

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

def scale(flag):
    for room in rooms:
        if flag == 'x_up':
            x = rooms[room].x
            rooms[room].x = int(x * 1.15)
        elif flag == 'x_down':
            x = rooms[room].x
            rooms[room].x = int(x / 1.15)
        elif flag == 'y_up':
            y = rooms[room].y
            rooms[room].y = int(y * 1.15)
        elif flag == 'y_down':
            y = rooms[room].y
            rooms[room].y = int(y / 1.15)
    draw_rooms()

def print_text(message, x, y, size):
    font_type = pygame.font.Font("visualize/Comic.ttf", size)
    text = font_type.render(message, True, (255, 255, 255))
    sc.blit(text, (x, y))
    pygame.display.update()

def part3():
    pepe = pygame.transform.scale(pepe_old, (rad * 4, rad * 4))
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT: exit()
        for room in rooms:
            sc.blit(pepe, (rooms[room].x - rad * 2, rooms[room].y - rad * 2))
            pygame.display.update()
            clock.tick(30)
    exit()

def part2():
    global rad
    rad = 5
    draw_rooms()
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT: exit()
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RETURN: part3()
                elif (event.key == pygame.K_UP or event.key == pygame.K_RIGHT) and event.mod == pygame.KMOD_LALT:
                    if rad < 100:
                        rad = int(rad * 1.25)
                        draw_rooms()
                elif (event.key == pygame.K_DOWN or event.key == pygame.K_LEFT) and event.mod == pygame.KMOD_LALT:
                    if rad > 5:
                        rad = int(rad / 1.25)
                        draw_rooms()
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
    #sc.fill((0, 0, 0))
    sc.blit(bg, (0, 0))
    print_text("instructions:", x, y, 30)
    print_text("i. use arrows to move graph.", x, y + 50, 20)
    print_text("ii. hold left shift to scale graph.", x, y + 75, 20)
    print_text("iii. hold left alt to scale rooms size (it will affect ants size).", x, y + 100, 20)
    print_text("iiii. when you're ready press enter to run algorithm.", x, y + 125, 20)
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
    #sc.fill((0, 0, 0))
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
