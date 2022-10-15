import sys


cache = [0 for _ in range((10 ** 3) + 1)]
cache[1] = 1
cache[2] = 2
    
for i in range(3, (10 ** 3) + 1):
    cache[i] = cache[i - 2] + cache[i - 1]

while True:
    a, b = map(int, sys.stdin.readline().split())
    if a == 0 and b == 0:
        break

    num = 1; count = 0
    while True:
        if cache[num] >= a and cache[num] <= b:
            count += 1
        if cache[num] > b:
            break
        num += 1
    
    print(count)