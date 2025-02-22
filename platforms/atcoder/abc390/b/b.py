#!/usr/bin/env python

n = int(input())
m = list(map(int, list(input().split(' '))))

a = -1
last_a = -1
r = -1
next = -1

for i in range(n):
	a = m[i]

	if i == 0:
		last_a = a
		continue

	elif i == 1:
		r = a / last_a
		last_a = a

	else:
		next = r * last_a
		last_a = a

		if next != a:
			print("No")
			exit(0)
	
print("Yes")
