import sys

table = [0 for _ in range(10000)]
num = int(sys.stdin.readline())
for i in range(num):
    temp = int(sys.stdin.readline())
    table[temp - 1] += 1

for j in range(1, 10001):
    for k in range(table[j - 1]):
        print(j)