#!/usr/bin/env python

from math import *

def read_list():
    return [int(i) for i in input().split]

px, py, qx, qy = read_list()
r, n = read_list()

while n:
    x, y = read_list()
    n = n - 1
