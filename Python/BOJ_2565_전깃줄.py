import sys

line = int(sys.stdin.readline())
table = []
for i in range(line):
    a, b = map(int, sys.stdin.readline().split())
    table.append((a, b))

table.sort()

dp = [1 for _ in range(line)]
for i in range(line):
    for j in range(i):
        if table[i][1] > table[j][1]:
            dp[i] = max(dp[i], dp[j] + 1)

print(line - max(dp))