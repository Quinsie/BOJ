import sys

n, m = map(int, sys.stdin.readline().split())
table = []
for a in range(n):
    table.append(list(map(int, sys.stdin.readline().split())))

dp = [[0 for _ in range(m)] for _ in range(n)]
dp[0][0] = table[0][0]
for i in range(n):
    for j in range(m):
        if i == 0 and j == 0:
            continue
        elif i > 0 and j == 0:
            dp[i][j] = dp[i - 1][j]
        elif i == 0 and j > 0:
            dp[i][j] = dp[i][j - 1]
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        
        if table[i][j] == 1:
            dp[i][j] += 1

print(dp[n - 1][m - 1])