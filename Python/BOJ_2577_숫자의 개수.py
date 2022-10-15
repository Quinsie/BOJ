import sys

total = 1
for i in range(3):
    temp = int(sys.stdin.readline())
    total *= temp

total = str(total)
for i in range(0, 10):
    count = 0
    for j in total:
        if j == str(i):
            count += 1
    print(count)