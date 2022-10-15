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

a, b = map(int, sys.stdin.readline().split())
print(a * b // gcd(a, b))