import sys
import collections
import copy

def bfs(x, y, chart):
    queue = collections.deque()
    queue.append((x, y))

    dx = [0, 0, 1, -1]; dy = [1, -1, 0, 0]
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            new_x = x + dx[i]; new_y = y + dy[i]
            if 0 <= new_x < column and 0 <= new_y < row:
                if chart[new_x][new_y] != 0:
                    chart[new_x][new_y] = 0
                    queue.append((new_x, new_y))

def melt(chart, x, y):
    count = 0
    dx = [0, 0, 1, -1]; dy = [1, -1, 0, 0]
    for i in range(4):
        new_x = x + dx[i]; new_y = y + dy[i]
        if 0 <= new_x < column and 0 <= new_y < row and chart[new_x][new_y] == 0:
            count += 1
    return count

column, row = map(int, sys.stdin.readline().split())
table = []
for i in range(column):
    table.append(list(map(int, sys.stdin.readline().split())))
melt_table = [[0 for _ in range(row - 2)] for _ in range(column - 2)]

time = 0
while True:
    time += 1
    for a in range(1, column - 1):
        for b in range(1, row - 1):
            if table[a][b] != 0:
                melt_table[a - 1][b - 1] = melt(table, a, b)

    for a in range(1, column - 1):
        for b in range(1, row - 1):
            table[a][b] -= melt_table[a - 1][b - 1]
            if table[a][b] < 0:
                table[a][b] = 0
    
    check_table = copy.deepcopy(table)
    iceberg = 0 # iceberg : counted at least one iceberg or not
    flag = 0 # flag : break program or not (at least two iceberg)
    for a in range(column):
        for b in range(row):
            if check_table[a][b] != 0:
                if iceberg == 0: # counted iceberg yet (0 counted)
                    bfs(a, b, check_table) # turn iceberg to zero
                    iceberg = 1
                else: # one iceberg has already counted and new one appeard
                    flag = 1 # turn on flag and break
                    break
        if flag == 1:
            break
    
    if flag == 1:
        print(time)
        break
    if iceberg == 0 and flag == 0:
        print(0)
        break