import sys

def fibo(n):
    cache = [0, 1, 0]
    cache[1] = 1

    if n < 2:
        return n
    else:
        count = 1
        while count < n:
            cache[2] = ((cache[0] % (10 ** 9)) + (cache[1] % (10 ** 9))) % (10 ** 9)
            cache[0] = cache[1]
            cache[1] = cache[2]
            count += 1
        return cache[2]

num = int(sys.stdin.readline())
if num < 0:
    num *= -1
    if num % 2 == 0:
        print(-1)
        print(fibo(num))
    else:
        print(1)
        print(fibo(num))

elif num == 0:
    print(0)
    print(0)

else:
    print(1)
    print(fibo(num))