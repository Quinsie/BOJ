import sys

num = int(sys.stdin.readline())
num_list = list(map(int, sys.stdin.readline().split()))
for i in range(1, len(num_list)):
    num_list[i] += num_list[i - 1]

case = int(sys.stdin.readline())
for j in range(case):
    start, end = map(int, sys.stdin.readline().split())
    if start < 2:
        total = num_list[end - 1]
    else:
        total = num_list[end - 1] - num_list[start - 2]
    print(total)