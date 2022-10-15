import sys
import collections

def search(x, y, chart, column, row): # search fire
    dx = [0, 0, 1, -1]; dy = [1, -1, 0, 0]
    for loof in range(4):
        new_x = x + dx[loof]; new_y = y + dy[loof]
        if 0 <= new_x < column and 0 <= new_y < row and chart[new_x][new_y] == '*':
            return 1
    return 0

def bfs(table, fire_pos, start_x, start_y, column, row):
    queue = collections.deque()
    queue.append((start_x, start_y, 0, 1)) # human move first
    while fire_pos:
        queue.append(fire_pos.pop())
    dx = [0, 0, 1, -1]; dy = [1, -1, 0, 0]
    check = [[0 for _ in range(row)] for _ in range(column)]
    check[start_x][start_y] = 1

    while queue:
        x, y, count, flag = queue.popleft()
        for i in range(4):
            new_x = x + dx[i]; new_y = y + dy[i]
            if new_x < 0 or new_x >= column or new_y < 0 or new_y >= row: # pos : side of map
                if flag == 1: # if human
                    return count + 1 # evade
            elif 0 <= new_x < column and 0 <= new_y < row: # pos : normal
                if flag == 0: # fire case
                    if table[new_x][new_y] == '.':
                        table[new_x][new_y] = '*'
                        queue.append((new_x, new_y, 0, flag))
                else: # human case
                    if table[new_x][new_y] == '.' and check[new_x][new_y] == 0:
                        order = search(new_x, new_y, table, column, row)
                        if order == 0: # no fire
                            check[new_x][new_y] = 1
                            queue.append((new_x, new_y, count + 1, flag))
    
    return 'IMPOSSIBLE'

case = int(sys.stdin.readline())
for loof in range(case):
    row, column = map(int, sys.stdin.readline().split())
    table = [[] for _ in range(column)]
    fire = []
    for i in range(column):
        temp = sys.stdin.readline().rstrip()
        for j in range(row):
            if temp[j] == '*':
                fire.append((i, j, 0, 0)) # pos_x, pos_y, count, flag = 0: fire
            elif temp[j] == '@':
                (start_x, start_y) = (i, j)
                table[i].append('.')
                continue
            table[i].append(temp[j])
    
    print(bfs(table, fire, start_x, start_y, column, row))