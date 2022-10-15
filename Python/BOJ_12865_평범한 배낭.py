import sys

product, bag = map(int, sys.stdin.readline().split())
weight = []; value = []
for i in range(product):
    w, v = map(int, sys.stdin.readline().split())
    weight.append(w); value.append(v)

dp = [0 for _ in range(bag + 1)]
for a in range(product):
    for b in range(bag, -1, -1):
        if weight[a] <= b:
            dp[b] = max(dp[b], dp[b - weight[a]] + value[a])

print(dp[bag])