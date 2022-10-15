import sys

def gcd(x, y):
    a = max(x, y); b = min(x, y)
    while b != 0:
        temp = a
        a = b
        b = temp % a
    return a

def lcm(x, y):
    return (x * y) // gcd(x, y)

num = int(sys.stdin.readline())
year_list = []
for i in range(num):
    year, a, b = map(int, sys.stdin.readline().split())
    year += lcm(a, b)
    year_list.append(year)

print(min(year_list))