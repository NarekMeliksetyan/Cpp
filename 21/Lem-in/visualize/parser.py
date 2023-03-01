from room import *

def add_room(room, lem):
    name = room[0]
    x = int(room[1]) * 10 + 640
    y = int(room[2]) * 20 + 360
    lem.rooms[name] = Room(x, y)

def add_start(room, lem):
    name = room[0]
    add_room(room, lem)
    lem.start = lem.rooms[name]

def add_end(room, lem):
    name = room[0]
    add_room(room, lem)
    lem.end = lem.rooms[name]

def parse_input(lem):
    readed = 0

    # Считываем количество муравьёв
    inp = input()
    while inp[0] == '#':
        inp = input()
    if inp.isdigit():
        lem.ant_cnt = int(inp)

    # Считываем комнаты
    while True:
        try:
            inp = input()
            if inp:
                if inp == '##start':
                    while inp[0] is '#':
                        inp = input()
                    add_start(inp.split(' '), lem)
                elif inp == "##end":
                    while inp[0] is '#':
                        inp = input()
                    add_end(inp.split(' '), lem)
                elif inp[0] == '#':
                    continue
                elif inp[0] == 'L':
                    lem.solution.append(inp)
                elif ' ' in inp:
                    add_room(inp.split(' '), lem)
                elif '-' in inp:
                    (room1, room2) = inp.split('-')
                    lem.rooms[room1].add_link(room2)
            readed += 1
        except EOFError:
            return readed
