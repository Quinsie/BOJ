import sys

def fibo_synonym(n):
    if n < 4:
        return 1
    
    count = n - 3
    cache = [1, 1, 1, 0]
    while count > 0:
        cache[3] = cache[0] + cache[2]
        cache[0] = cache[1]; cache[1] = cache[2]; cache[2] = cache[3]
        count -= 1
    
    return cache[3]

num = int(sys.stdin.readline())
print(fibo_synonym(num))