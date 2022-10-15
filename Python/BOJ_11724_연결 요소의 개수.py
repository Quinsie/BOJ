import sys
import collections

def bfs(point):
    queue = collections.deque()
    queue.append(point)
    check[point] = 1

    while queue:
        point = queue.popleft()
        for a in table[point]:
            if check[a] == 0:
                check[a] = 1
                queue.append(a)

point, line = map(int, sys.stdin.readline().split())
table = [[] for _ in range(point)]
for i in range(line):
    start, end = map(int, sys.stdin.readline().split())
    table[start - 1].append(end - 1)
    table[end - 1].append(start - 1)

check = [0 for _ in range(point)]
count = 0

for j in range(point):
    if check[j] == 0:
        count += 1
        bfs(j)

print(count)