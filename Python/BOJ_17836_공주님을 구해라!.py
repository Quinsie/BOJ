import sys
import collections

def bfs(table, column, row, limit):
    queue = collections.deque()
    queue.append((0, 0, 0, 0)) # x, y, time, sword
    check = [[[0, 0] for _ in range(row)] for _ in range(column)]
    check[0][0][0] = 1
    dx = [0, 0, 1, -1]; dy = [1, -1, 0, 0]

    while queue:
        x, y, time, sword = queue.popleft()
        if time > limit:
            return 'Fail'
        if (x, y) == (column - 1, row - 1) and time <= limit:
            return time
        if table[x][y] == 2:
            sword = 1
        
        for i in range(4):
            new_x = x + dx[i]; new_y = y + dy[i]
            if 0 <= new_x < column and 0 <= new_y < row:
                if sword == 0:
                    if table[new_x][new_y] != 1 and check[new_x][new_y][sword] == 0:
                        check[new_x][new_y][sword] = 1
                        queue.append((new_x, new_y, time + 1, sword))
                else:
                    if check[new_x][new_y][sword] == 0:
                        check[new_x][new_y][sword] = 1
                        queue.append((new_x, new_y, time + 1, sword))

    return 'Fail'


column, row, limit = map(int, sys.stdin.readline().split())
table = []
for i in range(column):
    table.append(list(map(int, sys.stdin.readline().split())))
print(bfs(table, column, row, limit))