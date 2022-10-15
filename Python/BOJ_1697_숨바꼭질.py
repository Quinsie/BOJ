import sys
import collections

def bfs():
    while queue:
        x, count = queue.popleft()
        if x == k:
            print(count)
            return
        
        if 0 <= x - 1 <= 100000 and table[x - 1] == 0:
            table[x - 1] = 1
            queue.append((x - 1, count + 1))
        if 0 <= x + 1 <= 100000 and table[x + 1] == 0:
            table[x + 1] = 1
            queue.append((x + 1, count + 1))
        if 0 <= x * 2 <= 100000 and table[x * 2] == 0:
            table[x * 2] = 1
            queue.append((x * 2, count + 1))

n, k = map(int, sys.stdin.readline().split())
table = [0 for _ in range(100001)]
table[n] = 1
queue = collections.deque()
queue.append((n, 0))
bfs()