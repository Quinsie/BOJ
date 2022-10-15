# BOJ 11004 : K번째 수

import sys

# input
n, k = map(int, sys.stdin.readline().split())
num = list(map(int, sys.stdin.readline().split()))

# progress
num.sort()

# output
print(num[k - 1])