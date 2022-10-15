import sys

n, k = map(int, sys.stdin.readline().split())

count = 0; result = 1
while count < k:
    result *= (n - count)/(count + 1)
    count += 1

print(int(result))