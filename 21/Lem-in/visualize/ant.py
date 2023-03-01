class Ant:
    def __init__(self, x_, y_):
        self.x = x_
        self.y = y_
        self.dx = x_
        self.dy = y_

    def set_coord(self, x_, y_):
        self.x = x_
        self.y = y_

    def new_dest(self, dest):
        self.dx = dest.x
        self.dy = dest.y

    def move_to(self, vel = 0.1):
        diff_x = abs(self.x - self.dx)
        diff_y = abs(self.y - self.dy)

        mv_x = diff_x * vel
        mv_y = diff_y * vel
        if mv_x < 1:
            mv_x = 1
        if mv_y < 1:
            mv_y = 1

        if diff_x < mv_x:
            self.x = self.dx
        else:
            if self.x < self.dx:
                self.x += mv_x
            else:
                self.x -= mv_x

        if diff_y < mv_y:
            self.y = self.dy
        else:
            if self.y < self.dy:
                self.y += mv_y
            else:
                self.y -= mv_y

    def coord(self):
        return (self.x, self.y)
