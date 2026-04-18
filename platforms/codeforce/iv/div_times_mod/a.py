n, k = list(map(int, input().split()))

x = k
while x <= 1000000000:
	d1 = x // k
	d2 = x % k
	 
	if d2 == 0:
		x = x + 1
		continue

	if (d1 * d2 == n):
		break

	x = x + 1

print(x)
