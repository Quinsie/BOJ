import sys

def gcd(x, y):
    a = max(x, y); b = min(x, y)
    while b != 0:
        temp = a
        a = b
        b = temp % a
    return a

a1, a2 = map(int, sys.stdin.readline().split())
b1, b2 = map(int, sys.stdin.readline().split())

c1 = (a1 * b2) + (b1 * a2)
c2 = a2 * b2

divisor = gcd(c1, c2)
c1 = c1 // divisor
c2 = c2 // divisor

print('%d %d' %(c1, c2))