import sys

num = int(sys.stdin.readline())

count = 0
while (2 ** count) < num:
    count += 1
count -= 1
print(int(2 * (num - (2 ** count))))