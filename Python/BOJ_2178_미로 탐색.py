import sys

def bfs(x, y, count):
    queue = [[x, y, count]]

    while queue:
        x, y, count = queue[0][0], queue[0][1], queue[0][2]
        del queue[0]

        for i in range(4):
            new_x = x + dx[i]; new_y = y + dy[i]

            if (new_x, new_y) == (row - 1, column - 1):
                print(count + 1)
                queue = []
                break
            if 0 <= new_x < row and 0 <= new_y < column:
                if table[new_x][new_y] == '1' and (new_x, new_y) not in visited:
                    queue.append([new_x, new_y, count + 1])
                    visited.append((new_x, new_y))

row, column = map(int, sys.stdin.readline().split())
table = []
for i in range(row):
    table.append(sys.stdin.readline().rstrip())

dx = [0, 0, 1, -1]; dy = [1, -1, 0, 0]
visited = [(0, 0)]
bfs(0, 0, 1)