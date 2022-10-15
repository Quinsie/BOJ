import sys

coin = int(sys.stdin.readline())
round_1 = list(map(int, sys.stdin.readline().split()))
round_2 = list(map(int, sys.stdin.readline().split()))

total = 0
for i in round_1:
    total += abs(i)
for j in round_2:
    total += abs(j)

print(total)