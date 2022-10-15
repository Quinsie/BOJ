import sys

def combination(n, r):
    total = 1; temp = r

    while temp > 0:
        total *= n
        n -= 1
        temp -= 1

    temp = 1
    while r > 0:
        temp *= r
        r -= 1

    return total // temp

case = int(sys.stdin.readline())
for i in range(case):
    r, n = map(int, sys.stdin.readline().split())
    print(combination(n, r))