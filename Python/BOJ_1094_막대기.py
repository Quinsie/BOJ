import sys

num = int(sys.stdin.readline())

count = 0
while num != 0:
    square = 0
    while (2 ** (square + 1)) <= num:
        square += 1
    num -= (2 ** square)
    count += 1

    if num == 0:
        break
    else:
        continue

print(count)