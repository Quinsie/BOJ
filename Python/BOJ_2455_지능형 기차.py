import sys

record = []
current = 0
for i in range(4):
    a, b = map(int, sys.stdin.readline().split(' '))
    current -= a
    current += b
    record.append(current)

print(max(record))