# M = 998244353
M = 11

def fast_exp(a, b, m):
    r = 1
    a %= m
    while b:
        if b & 1:
            r = (r * a) % m
        a = (a * a) % m
        b >>= 1
    return r

n, m = [int(n) for n in input().split()]
C = [int(n) for n in input().split()]

print(n, m)
print(C)

V = [fast_exp(i + 1, M - 2, M) for i in range(M-1)]
print(V)
