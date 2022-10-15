import sys
import collections

def check(x, y):
    for i in range(8):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < n and s[nx][ny] != "1":
            continue
        else: return False
    return True
def bfs():
    while b:
        x, y, d, cnt = b.popleft()
        if x == ex and y == ey and d == ed:
            return cnt
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if d == 0:
                if 0 <= nx < n and 0 <= ny < n and 0 <= ny - 1 < n and 0 <= ny + 1 < n and visit[nx][ny][0] == 0:
                    if s[nx][ny] != "1" and s[nx][ny - 1] != "1" and s[nx][ny + 1] != "1":
                        visit[nx][ny][0] = 1
                        b.append([nx, ny, 0, cnt + 1])
            elif d == 1:
                if 0 <= nx < n and 0 <= nx - 1 < n and 0 <= nx + 1 < n and 0 <= ny < n and visit[nx][ny][1] == 0:
                    if s[nx][ny] != "1" and s[nx - 1][ny] != "1" and s[nx + 1][ny] != "1":
                        visit[nx][ny][1] = 1
                        b.append([nx, ny, 1, cnt + 1])
        d = 0 if d == 1 else 1
        if check(x, y) and visit[x][y][d] == 0:
            visit[x][y][1] = 1
            b.append([x, y, d, cnt + 1])
    return 0   

n = int(sys.stdin.readline())
s = []
b = collections.deque()
e = collections.deque()
visit = [[[0 for i in range(2)] for i in range(n)] for i in range(n)]
dx = [1, -1, 0, 0, -1, -1, 1, 1]
dy = [0, 0, -1, 1, -1, 1, 1, -1]

for i in range(n):
    a = list(sys.stdin.readline().strip())
    s.append(a)
    for j in range(n):
        if a[j] == "B": b.append([i, j])
        if a[j] == "E": e.append([i, j])
if b[1][1] - b[0][1] == 1:
    b.append([b[1][0], b[1][1], 0, 0])
else:
    b.append([b[1][0], b[1][1], 1, 0])
if e[1][1] - e[0][1] == 1:
    ex, ey, ed = e[1][0], e[1][1], 0
else:
    ex, ey, ed = e[1][0], e[1][1], 1

for i in range(3):
    b.popleft()

visit[b[0][0]][b[0][1]][b[0][2]] = 1
print(bfs())