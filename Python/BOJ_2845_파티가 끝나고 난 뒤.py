import sys

a, b = map(int, sys.stdin.readline().split())
num_list = list(map(int, sys.stdin.readline().split()))
for i in num_list:
    print(i - (a * b), end = ' ')