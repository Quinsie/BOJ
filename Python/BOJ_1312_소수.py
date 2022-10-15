import sys

a, b, n = map(int, sys.stdin.readline().split())

count = 0
while True:
    a %= b
    count += 1
    a *= 10
    if count == n:
        print(a // b)
        break