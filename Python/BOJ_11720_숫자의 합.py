# BOJ 11720 : 숫자의 합

import sys

# input
num = int(sys.stdin.readline())
sample = sys.stdin.readline().rstrip()

# progress
total = 0
for i in sample:
    total += int(i)

# output
print(total)