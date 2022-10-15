import sys
import collections

def bfs(x, y, count, w):
    queue = collections.deque()
    queue.append((x, y, count, w))
    check = [[[0 for _ in range(wall + 1)] for _ in range(row)] for _ in range(column)]
    dx = [1, -1, 0, 0]; dy = [0, 0, 1, -1]
    while queue:
        x, y, count, w = queue.popleft()
        broken = wall - w
        if (x, y) == (column - 1, row - 1):
            return count
        
        for i in range(4):
            new_x = x + dx[i]; new_y = y + dy[i]
            if 0 <= new_x < column and 0 <= new_y < row:
                if check[new_x][new_y][broken] == 0:
                    if table[new_x][new_y] == 0:
                        queue.append((new_x, new_y, count + 1, w))
                        check[new_x][new_y][broken] = 1
                    elif table[new_x][new_y] == 1 and w > 0:
                        queue.append((new_x, new_y, count + 1, w - 1))
                        check[new_x][new_y][broken] = 1
                        check[new_x][new_y][broken + 1] = 1
    
    return -1

column, row, wall = map(int, sys.stdin.readline().split())
table = [[] for _ in range(column)]
for i in range(column):
    temp = sys.stdin.readline().rstrip()
    for j in temp:
        table[i].append(int(j))

print(bfs(0, 0, 1, wall))