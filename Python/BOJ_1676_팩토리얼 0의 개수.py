import sys

num = int(sys.stdin.readline())

count = 0
while num // 5 > 0:
    num = num // 5
    count += num

print(count)