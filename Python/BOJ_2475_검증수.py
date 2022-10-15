# BOJ 2475 : 검증수

import sys

# input
num_list = list(map(int, sys.stdin.readline().split(' ')))

# progress
for i in range(len(num_list)):
    num_list[i] = num_list[i] ** 2

total = 0
for j in num_list:
    total += j
result = total % 10

# output
print(result)