import sys

num, case = map(int, sys.stdin.readline().split())
num_list = list(map(int, sys.stdin.readline().split()))

for i in range(1, len(num_list)):
    num_list[i] += num_list[i - 1]

for j in range(case):
    start, end = map(int, sys.stdin.readline().split())
    if start == 1:
        print(num_list[end - 1])
    else:
        print(num_list[end - 1] - num_list[start - 2])