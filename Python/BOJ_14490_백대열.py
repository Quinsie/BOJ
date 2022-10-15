import sys

def gcd(x, y):
    a = max(x, y); b = min(x, y)
    while b != 0:
        temp = a
        a = b
        b = temp % a
    return a

a, b = map(int, sys.stdin.readline().split(':'))
divisor = gcd(a, b)
a = a // divisor
b = b // divisor

print('%d:%d' %(a, b))