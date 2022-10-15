import sys
import collections

def bfs(x, y):
    queue = collections.deque()
    queue.append((x, y))
    dx = [0, 0, 1, -1, 1, 1, -1, -1]
    dy = [1, -1, 0, 0, -1, 1, -1, 1]
    table[x][y] = 0

    while queue:
        x, y = queue.popleft()
        for n in range(8):
            new_x = x + dx[n]; new_y = y + dy[n]
            if 0 <= new_x < column and 0 <= new_y < row and table[new_x][new_y] == 1:
                table[new_x][new_y] = 0
                queue.append((new_x, new_y))

while True:
    row, column = map(int, sys.stdin.readline().split())
    if (row, column) == (0, 0):
        break

    table = []
    for i in range(column):
        table.append(list(map(int, sys.stdin.readline().split())))

    count = 0
    for a in range(column):
        for b in range(row):
            if table[a][b] == 1:
                count += 1
                bfs(a, b)

    print(count)