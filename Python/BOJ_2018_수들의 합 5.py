import sys

num = int(sys.stdin.readline())

count = 0; integer = 1
while True:
    if (num / integer) - (integer / 2) < 0.5:
        break

    if integer % 2 != 0:
        if num % integer == 0:
            count += 1
    else:
        if num % integer == integer // 2:
            count += 1

    integer += 1

print(count)