# Standard libraries:
from math import *

# Snippets:
def read_list(kind = int):
    return [kind(i) for i in input().split()]

# Computational Geometry:
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def distance(self, P):
        return hypot(self.x - P.x, self.y - P.y)

class Line:
    def __init__(self, P: Point, Q: Point):
        self.a = P.y - Q.y
        self.b = Q.x - P.x
        self.c = P.x * Q.y - Q.x * P.y

    def closest(self, P: Point):
        den = (self.a ** 2 + self.b ** 2)

        x = (self.b * (self.b * P.x - self.a * P.y) - self.a * self.c) / den
        y = (self.a * (-self.b * P.x + self.a * P.y) - self.b * self.c) / den

        return Point(x, y)

class Segment:
    def __init__(self, P: Point, Q: Point):
        self.P = P
        self.Q = Q

    def distance(self, R: Point):
        return (self.P.x * self.Q.y + self.P.y * R.x + self.Q.x * R.y) - (R.x * self.Q.y + R.y * self.P.x + self.Q.x * self.P.y)

    def contains(self, R: Point):
        return self.distance(R) == 0

    def closest(self, R: Point):
        A = Line(self.P, self.Q).closest(R)

        if self.contains(A):
            return A

        elif self.P.distance(R) <= self.Q.distance(R):
            return self.P

        else:
            return self.Q

