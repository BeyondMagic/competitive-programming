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
a, b = read_list()
print(a + b)
