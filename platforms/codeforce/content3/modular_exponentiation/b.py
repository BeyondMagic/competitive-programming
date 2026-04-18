a, b = list(map(int, input().split()))
if a == 0 or b == 0:
	print("YES")
else:
	if abs(a - b) != 1:
		print("NO")
	else:
		print("YES")

