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

def lcm(x, y):
    return x * y // gcd(x, y)

a, b = map(int, sys.stdin.readline().split())

multiplied = a * b; root = int(multiplied ** (1 / 2))
while True:
    if root % a == 0:
        break
    root += 1

num_1 = root
while True:
    num_2 = multiplied // num_1
    if gcd(num_1, num_2) == a and lcm(num_1, num_2) == b:
        print('%d %d' %(min(num_1, num_2), max(num_1, num_2)))
        break
    num_1 += a