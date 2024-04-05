# author:	beyondmagic, mathbergsant
# sensei:	Edson Alves
def decimal_to_base(old_n, base):
    n = 0

    for x in X:
        n = int(x) + n * base

    return n

X = input()
M = int(input())

# achar maior numero
d = 0
N = 0
for a in X:
    if int(a) > d:
        d = int(a)
        N = N + 1

n = d

while decimal_to_base(X, n + 1) <= M:
    n = n + 1

print(n - d)
