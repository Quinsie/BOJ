import sys

n, x = map(int, sys.stdin.readline().split(' '))
num = list(map(int, sys.stdin.readline().split(' ')))

for i in num:
    if i < x:
        print(i, end = ' ')