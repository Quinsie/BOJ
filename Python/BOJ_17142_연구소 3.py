import sys
import collections
import copy

def bfs(virus_activated):
    chart = copy.deepcopy(table)
    queue = collections.deque()
    dx = [0, 0, 1, -1]; dy = [1, -1, 0, 0]
    check = [[0 for _ in range(size)] for _ in range(size)]
    while virus_activated:
        temp = virus_activated.pop()
        check[temp[0]][temp[1]] = 1
        queue.append(temp)
    
    maximum = 0
    while queue:
        x, y, count = queue.popleft()
        for i in range(4):
            new_x = x + dx[i]; new_y = y + dy[i]
            if 0 <= new_x < size and 0 <= new_y < size and check[new_x][new_y] == 0:
                if chart[new_x][new_y] != 1:
                    if chart[new_x][new_y] == 0: # only if new_x new_y == 0, maximum compare.
                        if count + 1 > maximum:
                            maximum = count + 1
                    chart[new_x][new_y] = 2 # set to virus
                    check[new_x][new_y] = 1 # check pos
                    queue.append((new_x, new_y, count + 1))
    
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
        return maximum

def recursive(pos): # combinations.
    global minimum
    if pos == virus:
        virus_activated = []
        for j in range(virus):
            virus_activated.append(virus_list[cd[j]])

        num = bfs(virus_activated)
        if num == -1:
            return
        minimum = min(num, minimum)
        return
    
    for i in range(max(cd) + 1, len(virus_list)):
        cd[pos] = i
        recursive(pos + 1)
        cd[pos] = -1

size, virus = map(int, sys.stdin.readline().split())
table = []
virus_list = []
for i in range(size):
    temp = list(map(int, sys.stdin.readline().split()))
    for j in range(len(temp)):
        if temp[j] == 2:
            virus_list.append((i, j, 0))
    table.append(temp)

cd = [-1 for _ in range(virus)]
minimum = 2502
recursive(0)

if minimum == 2502:
    print(-1)
else:
    print(minimum)