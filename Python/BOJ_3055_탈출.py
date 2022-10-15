import sys
import collections
from tracemalloc import start

def bfs(chart, start_x, start_y, water, end_x, end_y):
    queue = collections.deque()
    for i in water:
        queue.append(i)
    queue.append((start_x, start_y, 0, 0))
    dx = [1, -1, 0, 0]; dy = [0, 0, 1, -1]
    check = [[0 for _ in range(row)] for _ in range(column)]
    check[start_x][start_y] = 1

    while queue:
        x, y, count, flag = queue.popleft()
        if (x, y) == (end_x, end_y) and flag == 0: # 도착하면 반환
            return count

        for i in range(4):
            new_x = x + dx[i]; new_y = y + dy[i]
            if 0 <= new_x < column and 0 <= new_y < row:
                if flag == 0: # 현재 이동대상이 고슴도치인 경우
                    if chart[new_x][new_y] == '.' or chart[new_x][new_y] == 'D':
                        if check[new_x][new_y] == 0:
                            check[new_x][new_y] = 1
                            queue.append((new_x, new_y, count + 1, flag))
                else: # 현재 이동대상이 물인 경우
                    if chart[new_x][new_y] == '.':
                        chart[new_x][new_y] = '*'
                        queue.append((new_x, new_y, 0, flag))
        
    return 'KAKTUS' # 도착 못하면 반환

column, row = map(int, sys.stdin.readline().split())
table = [[] for _ in range(column)]
for i in range(column):
    temp = sys.stdin.readline().rstrip()
    for j in temp:
        table[i].append(j)

water = []
for i in range(column):
    for j in range(row):
        if table[i][j] == '*':
            water.append((i, j, 0, 1)) # 3번째는 count, 4번째는 물/고슴도치 판정 // 0이면 고슴도치, 1이면 물
        elif table[i][j] == 'S':
            table[i][j] = '.'
            start_x = i; start_y = j
        elif table[i][j] == 'D':
            end_x = i; end_y = j

print(bfs(table, start_x, start_y, water, end_x, end_y))