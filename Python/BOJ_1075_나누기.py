import sys

num = int(sys.stdin.readline())
divisor = int(sys.stdin.readline())

for i in range((num // 100) * 100, ((num // 100) * 100) + 100):
    if i % divisor == 0:
        result = str(i)
        print(result[len(result) - 2:])
        break