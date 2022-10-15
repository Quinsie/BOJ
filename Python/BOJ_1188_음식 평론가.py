import sys

def gcd(x, y):
    a = max(x, y); b = min(x, y)
    while b != 0:
        temp = a
        a = b
        b = temp % b
    return a

def lcm(x, y):
    return (x * y) // gcd(x, y)


sausage, people = map(int, sys.stdin.readline().split())

k = (sausage * people) // lcm(sausage, people)
if gcd(sausage, people) != 0:   # 서로소가 아니라면(기약분수가 아니라면)
    people = people // gcd(sausage, people)

print(k * (people - 1))