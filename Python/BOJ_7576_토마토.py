import sys
import collections

def bfs():
    global maximum
    while queue:
        x, y, count = queue.popleft()

        if count > maximum:
            maximum = count

        for i in range(4):
            new_x = x + dx[i]; new_y = y + dy[i]
            if 0 <= new_x < row and 0 <= new_y < column and table[new_x][new_y] == 0:
                table[new_x][new_y] = 1
                queue.append((new_x, new_y, count + 1))

column, row = map(int, sys.stdin.readline().split())
table = []
for i in range(row):
    table.append(list(map(int, sys.stdin.readline().split())))

queue = collections.deque()
for j in range(row):
    for k in range(column):
        if table[j][k] == 1:
            queue.append((j, k, 0))

dx = [0, 0, 1, -1]; dy = [1, -1, 0, 0]
maximum = 0
bfs()

flag = False
for l in range(row):
    for m in range(column):
        if table[l][m] == 0:
            flag = True
            break
    if flag == True:
        break

if flag == False:
    print(maximum)
else:
    print(-1)