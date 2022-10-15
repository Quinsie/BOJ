import sys
import collections
import copy

def bfs(table, virus_loc, size):
    chart = copy.deepcopy(table)
    queue = collections.deque()
    dx = [0, 0, 1, -1]; dy = [1, -1, 0, 0]
    while virus_loc:
        temp = virus_loc.pop()
        chart[temp[0]][temp[1]] = 2
        queue.append(temp)
    
    time = 0
    while queue:
        x, y, cnt = queue.popleft()
        if cnt > time:
            time = cnt

        for k in range(4):
            new_x = x + dx[k]; new_y = y + dy[k]
            if 0 <= new_x < size and 0 <= new_y < size:
                if chart[new_x][new_y] == 0:
                    chart[new_x][new_y] = 1
                    queue.append((new_x, new_y, cnt + 1))
    
    flag = 0
    for n in range(size):
        for m in range(size):
            if chart[n][m] == 0:
                flag = 1
                break
        if flag == 1:
            break
    
    if flag == 1:
        return -1
    else:
        return time

def recursive(pos, cor, virus, virus_num, table, size):
    global minimum
    if pos == virus_num:
        virus_loc = []
        for j in range(virus_num):
            virus_loc.append(virus[cor[j]])
        num = bfs(table, virus_loc, size)
        if num == -1:
            return
        if num < minimum:
            minimum = num
        return
    
    for i in range(max(cor) + 1, len(virus)):
        cor[pos] = i
        recursive(pos + 1, cor, virus, virus_num, table, size)
        cor[pos] = -1

size, virus_num = map(int, sys.stdin.readline().split())
table = []
virus = []
for i in range(size):
    temp = list(map(int, sys.stdin.readline().split()))
    for j in range(len(temp)):
        if temp[j] == 2:
            virus.append((i, j, 0))
            temp[j] = 0
    table.append(temp)

minimum = 2501
cor = [-1 for _ in range(virus_num)]
recursive(0, cor, virus, virus_num, table, size)

if minimum == 2501:
    print(-1)
else:
    print(minimum)