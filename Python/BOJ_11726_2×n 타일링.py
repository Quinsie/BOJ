import sys

def tile(n):
    if n < 3:
        return n
    
    count = n - 2
    cache = [1, 2, 0]
    while count != 0:
        cache[2] = ((cache[0] % 10007) + (cache[1] % 10007)) % 10007
        cache[0] = cache[1]
        cache[1] = cache[2]
        count -= 1
    return cache[2]

num = int(sys.stdin.readline())
print(tile(num))