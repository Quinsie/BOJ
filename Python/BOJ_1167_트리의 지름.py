import sys
import collections

def bfs(num):
    dist, node = 0,0
    q = collections.deque()
    q.append((num, 0))
    check[num] = True
    while q:
        now, now_dist = q.popleft()
        for i in adj[now]:
            if check[i[0]] == False:
                check[i[0]] = True
                q.append((i[0], i[1] + now_dist))
                
                if now_dist + i[1] > dist:
                    dist = now_dist + i[1]
                    node = i[0]
    return dist, node

n = int(sys.stdin.readline())

adj = [[] for _ in range(n)]
for i in range(n):
    temp = list(map(int, sys.stdin.readline().split()))
    for j in range(1, len(temp) - 1, 2):
        adj[temp[0] - 1].append((temp[j] - 1, temp[j + 1]))

check = [False] * n
a,b = bfs(0)
check = [False] * n
print(bfs(b)[0])