# pisano period, modular arithmetic

import sys

def fibo(n):
    if n < 2:
        return n
    cache = [0, 1, 1]
    count = n - 2
    while count != 0:
        cache[0] = cache[1]
        cache[1] = cache[2]
        cache[2] = ((cache[0] % 1000000) + (cache[1] % 1000000)) % 1000000
        count -= 1
    return cache[2]

num = int(sys.stdin.readline())
print(fibo(num % 1500000))