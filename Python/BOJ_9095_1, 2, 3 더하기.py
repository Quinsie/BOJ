import sys

def solve(num):
    if num < 3:
        return num
    elif num == 3:
        return 4
    
    count = num - 3
    cache = [1, 2, 4, 0]
    while count > 0:
        cache[3] = cache[0] + cache[1] + cache[2]
        cache[0] = cache[1]; cache[1] = cache[2]; cache[2] = cache[3]
        count -= 1
    
    return cache[3]

case = int(sys.stdin.readline())
for turn in range(case):
    num = int(sys.stdin.readline())
    print(solve(num))