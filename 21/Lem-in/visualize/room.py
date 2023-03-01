class Room():
    def __init__(self, x_, y_):
        self.x = x_
        self.y = y_
        self.links = set()

    def add_link(self, lnk):
        self.links.add(lnk)

    def coord(self):
        return (self.x, self.y)
