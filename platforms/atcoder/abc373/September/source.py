#!/usr/bin/env python

from math import *

t = 0

i = 1
while i <= 12:
    s = input()
    if len(s) == i:
        t = t + 1

    i = i + 1
print(t)
