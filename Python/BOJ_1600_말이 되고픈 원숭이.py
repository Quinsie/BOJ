import sys
import collections

def bfs(x, y, count, move, switch):
    queue = collections.deque()
    queue.append((x, y, count, move, switch))

    dx = [1, -1, 0, 0, 1, 1, 2, 2, -1, -1, -2, -2]
    dy = [0, 0, 1, -1, 2, -2, 1, -1, 2, -2, 1, -1]
    check = [[[0 for _ in range(horse + 1)] for _ in range(row)] for _ in range(column)]
    check[x][y][switch] = 1

    minimum = column * row * 2
    while queue:
        x, y, count, move, switch = queue.popleft()
        if (x, y) == (column - 1, row - 1) and count < minimum:
            minimum = count

        if move > 0:
            for j in range(4, 12):
                new_x = x + dx[j]; new_y = y + dy[j]
                if 0 <= new_x < column and 0 <= new_y < row:
                    if check[new_x][new_y][switch + 1] == 0 and table[new_x][new_y] == 0:
                        check[new_x][new_y][switch + 1] = 1
                        queue.append((new_x, new_y, count + 1, move - 1, switch + 1))

        for i in range(4):
            new_x = x + dx[i]; new_y = y + dy[i]
            if 0 <= new_x < column and 0 <= new_y < row:
                if check[new_x][new_y][switch] == 0 and table[new_x][new_y] == 0:
                    check[new_x][new_y][switch] = 1
                    queue.append((new_x, new_y, count + 1, move, switch))

    if minimum == column * row * 2:
        return -1
    else:
        return minimum

horse = int(sys.stdin.readline())
row, column = map(int, sys.stdin.readline().split())
table = []
for _ in range(column):
    table.append(list(map(int, sys.stdin.readline().split())))

print(bfs(0, 0, 0, horse, 0))