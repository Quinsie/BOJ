import sys

def fibo_called(n):
    if n == 0:
        return 1
    if n == 1:
        return 1
    if n == 2:
        return 3
    
    result = 5
    cache = [2, 2, 0]
    count = n - 3
    while count > 0:
        cache[2] = cache[0] + cache[1]
        result = ((result % 1000000007) + (cache[2] % 1000000007)) % 1000000007
        cache[0] = cache[1]; cache[1] = cache[2]
        count -= 1
    
    return result

num = int(sys.stdin.readline())
print(fibo_called(num))