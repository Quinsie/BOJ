import sys

num = sys.stdin.readline().rstrip()

count = 0
if num[0] != num[len(num) - 1]:
    for i in range(1, len(num)):
        if num[i] != num[i - 1]:
            count += 1
    print((count // 2) + 1)

else:
    for i in range(1, len(num)):
        if num[i] != num[i - 1]:
            count += 1
    print(count // 2)