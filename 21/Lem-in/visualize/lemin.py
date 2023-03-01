class Lemin():
    def __init__(self):
        self.start = 0
        self.end = 0
        self.rooms = dict()

        self.ants = dict()
        self.ant_cnt = 0
        self.solution = list()

    def st_coord(self):
        st_x = self.start.x
        st_y = self.start.y
        return (st_x, st_y)

    def en_coord(self):
        en_x = self.end.x
        en_y = self.end.y
        return (en_x, en_y)
