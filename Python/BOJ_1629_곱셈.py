import sys

a, b, c = map(int, sys.stdin.readline().split())

ans = 1
muls = a
while (b > 0):
    if b % 2:
        ans *= muls
        ans %= c
    muls *= muls
    muls %= c
    b >>= 1

print(ans)