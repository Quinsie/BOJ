import sys
import collections

def bfs(x, y, count, wall):
    queue = collections.deque()
    queue.append((x, y, count, wall))

    check_no_wall = [[0 for _ in range(row)] for _ in range(column)]
    check_wall = [[0 for _ in range(row)] for _ in range(column)]
    check_no_wall[0][0] = 1
    dx = [0, 0, 1, -1]; dy = [1, -1, 0, 0]
    while queue:
        x, y, count, wall = queue.popleft()

        if (x, y) == (column - 1, row - 1):
            return count
        
        for i in range(4):
            new_x = x + dx[i]; new_y = y + dy[i]
            if 0 <= new_x < column and 0 <= new_y < row:
                if wall == 1:
                    if check_no_wall[new_x][new_y] == 0:
                        if table[new_x][new_y] == 1:
                            queue.append((new_x, new_y, count + 1, 0))
                            check_no_wall[new_x][new_y] = 1
                            check_wall[new_x][new_y] = 1
                        else:
                            queue.append((new_x, new_y, count + 1, 1))
                            check_no_wall[new_x][new_y] = 1
                else:
                    if check_wall[new_x][new_y] == 0:
                        if table[new_x][new_y] == 0:
                            queue.append((new_x, new_y, count + 1, 0))
                            check_wall[new_x][new_y] = 1

    return -1

column, row = map(int, sys.stdin.readline().split())
table = [[] for _ in range(column)]
for a in range(column):
    temp = sys.stdin.readline().rstrip()
    for b in range(row):
        table[a].append(int(temp[b]))
print(bfs(0, 0, 1, 1))