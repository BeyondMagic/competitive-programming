#!/usr/bin/env python

from math import *

# Snippets:
def read_list():
    return [int(i) for i in input().split()]

# Computational Geometry:
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Segment:
    def __init__(self, P: Point, Q: Point):
        self.P = P
        self.Q = Q

    def distance(self, R: Point):
        return (self.P.x * self.Q.y + self.P.y * R.x + self.Q.x * R.y) - (R.x * self.Q.y + R.y * self.P.x + self.Q.x * self.P.y)

# Main program:
px, py, qx, qy = read_list()
r, n = read_list()

segment = Segment(Point(px, py), Point(qx, qy))

total = 0
while n:
    x, y = read_list()
    if segment.distance(Point(x, y)):
        total += r
    n = n - 1

print(total if total else "Bom trabalho!")
