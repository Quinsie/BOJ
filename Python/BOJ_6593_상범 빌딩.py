import sys
import collections

def bfs(start, end):
    queue = collections.deque()
    queue.append((start[0], start[1], start[2], 0))
    
    check = [[[0 for _ in range(row)] for _ in range(column)] for _ in range(height)]
    check[start[0]][start[1]][start[2]] = 1
    dx = [0, 0, 0, 0, 1, -1]; dy = [0, 0, 1, -1, 0, 0]; dz = [1, -1, 0, 0, 0, 0]

    while queue:
        z, x, y, count = queue.popleft()
        if (z, x, y) == end:
            print('Escaped in %d minute(s).' %(count))
            return
        
        for i in range(6):
            new_z = z + dz[i]; new_x = x + dx[i]; new_y = y + dy[i]
            if 0 <= new_z < height and 0 <= new_x < column and 0 <= new_y < row:
                if check[new_z][new_x][new_y] == 0 and table[new_z][new_x][new_y] != '#':
                    check[new_z][new_x][new_y] = 1
                    queue.append((new_z, new_x, new_y, count + 1))

    print('Trapped!')

while True:
    height, column, row = map(int, sys.stdin.readline().split())
    if (height, column, row) == (0, 0, 0):
        break

    table = []
    for i in range(height):
        temp_list = []
        for j in range(column):
            temp = sys.stdin.readline().rstrip()
            if 'S' in temp:
                start = (i, j, temp.index('S'))
            elif 'E' in temp:
                end = (i, j, temp.index('E'))
            temp_list.append(temp)
        table.append(temp_list)
        sys.stdin.readline()
    
    bfs(start, end)