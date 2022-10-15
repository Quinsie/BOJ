import sys

num = int(sys.stdin.readline())
num_list = [0] + list(map(int, sys.stdin.readline().split()))
dp = [0 for _ in range(num + 1)]

for i in range(1, num + 1):
    for j in range(i):
        if num_list[j] < num_list[i]:
            dp[i] = max(dp[i], dp[j] + num_list[i])

print(max(dp))