import sys

def gcd(x, y):
    big = max(x, y); small = min(x, y)
    remainder = big % small

    if small == 0:
        return big
    
    if remainder == 0:
        return small
    else:
        return gcd(small, remainder)

num = int(sys.stdin.readline())
for i in range(num):
    a, b = map(int, sys.stdin.readline().split())
    print('%d %d' %(a * b // gcd(a, b), gcd(a, b)))