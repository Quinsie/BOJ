import sys

a, b = map(int, sys.stdin.readline().split(' '))
if a == b:
    print(0)
elif a != b:
    print(max(a, b) - min(a, b) - 1)

for i in range(min(a, b) + 1, max(a, b) - 1):
    print(i, end = ' ')
if (max(a, b) - 1 != min(a, b)) and a != b:
    print(max(a, b) - 1)