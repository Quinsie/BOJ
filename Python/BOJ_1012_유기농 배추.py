import sys
sys.setrecursionlimit(10000)

def search(x, y):
    visited.append((x, y))
    for i in range(4):
        new_x = x + dx[i]; new_y = y + dy[i]
        if 0 <= new_x < row and 0 <= new_y < column:
            if table[new_x][new_y] == 1 and (new_x, new_y) not in visited:
                search(new_x, new_y)

case = int(sys.stdin.readline())
for i in range(case):
    column, row, cabbage = map(int, sys.stdin.readline().split())
    table = [[0 for _ in range(column)] for _ in range(row)]
    for j in range(cabbage):
        x, y = map(int, sys.stdin.readline().split())
        table[y][x] = 1
    
    count = 0
    visited = []
    dx = [1, -1, 0, 0]; dy = [0, 0, 1, -1]
    for k in range(row):
        for l in range(column):
            if table[k][l] == 1 and (k, l) not in visited:
                count += 1
                search(k, l)
    
    print(count)