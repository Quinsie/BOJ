import sys

def padoban(n):
    if n < 4:
        return 1
    elif n < 6:
        return 2
    else:
        cache = [1, 1, 1, 2, 2, 0]
        while n > 5:
            cache[5] = cache[0] + cache[4]
            cache[:5] = cache[1:]
            n -= 1
        return cache[5]

case = int(sys.stdin.readline())
for i in range(case):
    n = int(sys.stdin.readline())
    print(padoban(n))