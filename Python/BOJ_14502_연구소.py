import sys
import collections

def bfs(lab):
    check = [[0 for _ in range(row)] for _ in range(column)]
    for i in range(column):
        for j in range(row):
            check[i][j] = lab[i][j]

    queue = collections.deque()
    for i in range(column):
        for j in range(row):
            if check[i][j] == 2:
                queue.append((i, j))

    dx = [1, -1, 0, 0]; dy = [0, 0, 1, -1]
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            new_x = x + dx[i]; new_y = y + dy[i]
            if 0 <= new_x < column and 0 <= new_y < row and check[new_x][new_y] == 0:
                check[new_x][new_y] = 2
                queue.append((new_x, new_y))
    
    zero_count = 0
    for i in range(column):
        for j in range(row):
            if check[i][j] == 0:
                zero_count += 1
    return zero_count

def recursive(pos):
    global maximum
    if pos == 3:
        for i in cor:
            x = i // row; y = i % row
            table[x][y] = 1
        num = bfs(table)
        if num > maximum:
            maximum = num
        for j in cor:
            x = j // row; y = j % row
            table[x][y] = 0
        return
    
    for i in range(max(cor) + 1, column * row):
        if table[i // row][i % row] == 0:
            cor[pos] = i
            recursive(pos + 1)
            cor[pos] = -1

column, row = map(int, sys.stdin.readline().split())
table = []
for i in range(column):
    table.append(list(map(int, sys.stdin.readline().split())))

maximum = 0
cor = [-1 for _ in range(3)]
recursive(0)
print(maximum)