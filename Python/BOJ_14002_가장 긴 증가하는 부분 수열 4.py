import sys

num = int(sys.stdin.readline())
num_list = list(map(int, sys.stdin.readline().split()))
dp = [1 for _ in range(num)]

for i in range(num):
    for j in range(i):
        if num_list[j] < num_list[i]:
            dp[i] = max(dp[i], dp[j] + 1)

now = max(dp)
pos = num - 1
ans = []
while now > 0:
    if dp[pos] == now:
        ans.append(num_list[pos])
        now -= 1
    pos -= 1

print(max(dp))
for i in range(len(ans) - 1, -1, -1):
    print(ans[i], end = ' ')