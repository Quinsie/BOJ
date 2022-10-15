# BOJ 8393 : 합

import sys

# input
num = int(sys.stdin.readline())

# progress
total = 0
for i in range(1, num + 1):
    total += i

# output
print(total)