import sys

# input
num = int(sys.stdin.readline())

# progress
def gcd(x, y):
    big = max(x, y); small = min(x, y)
    remainder = big % small

    if small == 0:
        return big
    
    if remainder == 0:
        return small
    else:
        return gcd(small, remainder)

def lcm(x, y):
    return x * y // gcd(x, y)

for i in range(num):
     a, b = map(int, sys.stdin.readline().split())
     print(lcm(a, b))