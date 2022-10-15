# BOJ 2739 : 구구단

import sys

# input
num = int(sys.stdin.readline())

# output
for i in range(1, 10):
    print('%d * %d = %d' %(num, i, num * i))