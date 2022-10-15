import sys

n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))
b = list(map(int, sys.stdin.readline().split()))

a.sort()
b.sort(reverse = True)
total = 0
for i in range(n):
    total += a[i] * b[i]

print(total)