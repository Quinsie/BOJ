import sys

day, chapter = map(int, sys.stdin.readline().split())
time = []; page = []
for i in range(chapter):
    t, p = map(int, sys.stdin.readline().split())
    time.append(t); page.append(p)

dp = [0 for _ in range(day + 1)]
for a in range(chapter):
    for b in range(day, -1, -1):
        if time[a] <= b:
            dp[b] = max(dp[b], dp[b - time[a]] + page[a])

print(dp[day])