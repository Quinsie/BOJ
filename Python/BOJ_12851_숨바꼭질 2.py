import sys
import collections

def bfs():
    if n >= k:
        minimum.append(n - k)
        return

    while queue:
        x, count = queue.popleft()

        if minimum:
            if count == minimum[0]:
                return

        if x * 2 == k or x + 1 == k or x - 1 == k:
            minimum.append(count + 1)
            continue

        dx = [x * 2, x + 1, x - 1]
        for i in range(3):
            if 0 <= dx[i] <= 100000:
                if table[dx[i]] == 0 or table[dx[i]] >= count + 1:
                    table[dx[i]] = count + 1
                    queue.append((dx[i], count + 1))

n, k = map(int, sys.stdin.readline().split())
table = [0 for _ in range(100001)]
table[n] = 1
queue = collections.deque()
queue.append((n, 0))
minimum = []
bfs()
print(minimum[0])
print(len(minimum))