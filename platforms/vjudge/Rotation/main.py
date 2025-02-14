a = input()
b = input()

c = a[::-1]
a_new = b[::-1]
b_new = c

print("YES" if a == a_new and b_new == b else "NO")