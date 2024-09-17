#!/usr/bin/env python

from math import *

# Snippets:
def read_list():
    return [int(i) for i in input().split()]

# Main program:
B, b, h, alpha = read_list()

k =  h / sin(alpha * pi / 180)
m = sqrt(k ** 2 - h ** 2)
x = B - (m + b)
y = sqrt(x ** 2 + h ** 2)

print(k + B + b + y)
