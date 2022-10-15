import sys
import collections

def bfs():
    global maximum
    while queue:
        z, x, y, count = queue.popleft()

        if count > maximum:
            maximum = count

        for i in range(6):
            new_x = x + dx[i]; new_y = y + dy[i]; new_z = z + dz[i]
            if 0 <= new_x < row and 0 <= new_y < column and 0 <= new_z < height:
                if table[new_z][new_x][new_y] == 0:
                    table[new_z][new_x][new_y] = 1
                    queue.append((new_z, new_x, new_y, count + 1))

column, row, height = map(int, sys.stdin.readline().split())
table = []
for i in range(height):
    temp = []
    for j in range(row):
        temp.append(list(map(int, sys.stdin.readline().split())))
    table.append(temp)

queue = collections.deque()
for a in range(height):
    for b in range(row):
        for c in range(column):
            if table[a][b][c] == 1:
                queue.append((a, b, c, 0))

dx = [0, 0, 0, 0, 1, -1]; dy = [0, 0, 1, -1, 0, 0]; dz = [1, -1, 0, 0, 0, 0]
maximum = 0
bfs()

flag = False
for d in range(height):
    for e in range(row):
        for f in range(column):
            if table[d][e][f] == 0:
                flag = True
                break
        if flag == True:
            break
    if flag == True:
        break

if flag == False:
    print(maximum)
else:
    print(-1)