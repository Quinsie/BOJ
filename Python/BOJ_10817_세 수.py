import sys

num = list(map(int, sys.stdin.readline().split(' ')))
num.sort()
print(num[1])