import sys

num = []
for i in range(10):
    temp = int(sys.stdin.readline())
    num.append(temp)

remainder = []
for j in num:
    temp2 = j % 42
    remainder.append(temp2)

remainder.sort()
count = 1
for k in range(1, len(remainder)):
    if remainder[k] != remainder[k-1]:
        count += 1

print(count)