import sys

# input
num = int(sys.stdin.readline())
num_list = []
for i in range(num):
    num_list.append(int(sys.stdin.readline()))

# progress
num_list.sort(reverse = True)

# output
for j in num_list:
    print(j)