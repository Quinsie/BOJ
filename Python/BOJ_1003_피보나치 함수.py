import sys

def fibo(n):
    if n == 0:
        return [1, 0]
    elif n == 1:
        return [0, 1]
    cache = [0 for _ in range(n + 1)]
    cache[1] = 1
    for i in range(2, n + 1):
        cache[i] = cache[i - 1] + cache[i - 2]
    return [cache[n - 1], cache[n]]

case = int(sys.stdin.readline())
for i in range(case):
    num = int(sys.stdin.readline())
    temp = fibo(num)
    print("%d %d" %(temp[0], temp[1]))