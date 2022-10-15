import sys

# input
num = int(sys.stdin.readline())
num_list = []
for i in range(num):
    temp = int(sys.stdin.readline())
    num_list.append(temp)

# progress
num_list.sort()
count = 1
length = len(num_list)
while count < length:
    if num_list[count] == num_list[count - 1]:
        del num_list[count]
        continue
    count += 1
    length = len(num_list)

# output
for j in num_list:
    print(j)