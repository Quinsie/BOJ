import sys

num = int(sys.stdin.readline())
num_length = len(str(num))
length = 1

count = 0
while len(str(length)) < num_length:
    count += len(str(length)) * length * 9
    length *= 10

count += (num - length + 1) * len(str(length))
print(count)