import sys

num = int(sys.stdin.readline())
case = list(map(int, sys.stdin.readline().split(' ')))
print(min(case), max(case))