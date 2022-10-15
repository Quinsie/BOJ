import collections
import sys

def bfs():
    queue = collections.deque()
    queue.append((0, 0))

    check = [[0 for _ in range(row)] for _ in range(column)]
    table[0][0] = 2
    check[0][0] = 1

    while queue:
        x, y = queue.popleft()
        for k in range(4):
            new_x = x + dx[k]; new_y = y + dy[k]
            if 0 <= new_x < column and 0 <= new_y < row:
                if table[new_x][new_y] == 0 or table[new_x][new_y] == 2:
                    if check[new_x][new_y] == 0:
                        table[new_x][new_y] = 2
                        check[new_x][new_y] = 1
                        queue.append((new_x, new_y))

def melt(x, y):
    two_count = 0
    for k in range(4):
        new_x = x + dx[k]; new_y = y + dy[k]
        if 0 <= new_x < column and 0 <= new_y < row and table[new_x][new_y] == 2:
            two_count += 1 # one side 2 : count++
        if two_count >= 2:
            return 1 # two side 2 : melt
    return 0 # else stay

column, row = map(int, sys.stdin.readline().split())
table = []
for i in range(column):
    table.append((list(map(int, sys.stdin.readline().split()))))

time = 0
dx = [0, 0, 1, -1]; dy = [1, -1, 0, 0]
while True:
    bfs() # change zero to 2 (table)
    count = 0
    for i in range(column):
        for j in range(row):
            if table[i][j] == 1:
                table[i][j] -= melt(i, j)
                count += 1
    
    if count == 0: # no count = no cheese. break.
        print(time)
        break
    else: # else : save count to prev count and melt cheese
        prev_count = count
    
    time += 1 # every loof add count