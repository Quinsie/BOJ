import sys

sum = 0; count = 1
target = int(sys.stdin.readline())

while sum < target:
    sum += count
    count += 1

if sum == target:
    print(count - 1)
else:
    print(count - 2)