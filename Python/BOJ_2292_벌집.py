import sys

num = int(sys.stdin.readline())

level = 1
while num > 1:
    num -= (6 * level)
    level += 1
print(level)