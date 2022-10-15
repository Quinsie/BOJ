import sys

num = int(sys.stdin.readline())
cow = [2 for _ in range(10)]

count = 0
for i in range(num):
    a, b = map(int, sys.stdin.readline().split())
    if cow[a - 1] == 2:
        cow[a - 1] = b
    else:
        if cow[a - 1] != b:
            count += 1
            cow[a - 1] = b

print(count)