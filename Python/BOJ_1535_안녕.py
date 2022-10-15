import sys

people = int(sys.stdin.readline())
hp = list(map(int, sys.stdin.readline().split()))
happy = list(map(int, sys.stdin.readline().split()))

dp = [0 for _ in range(100)]
for a in range(people):
    for b in range(99, -1, -1):
        if hp[a] <= b:
            dp[b] = max(dp[b], dp[b - hp[a]] + happy[a])

print(dp[99])