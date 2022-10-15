# BOJ 1252 : 이진수 덧셈

import sys

# input
bin1, bin2 = sys.stdin.readline().split(' ')

# progress
num1 = int(bin1, 2); num2 = int(bin2, 2)
total = num1 + num2
bin_total = str(bin(total))

# output
print(bin_total[2:])