import sys
import collections

def bfs(start_x, start_y, end_x, end_y, column, row, table):
    queue = collections.deque()
    queue.append((start_x - 1, start_y - 1, 0, 0)) # count, flag
    check = [[[0, 0] for _ in range(row)] for _ in range(column)]
    check[start_x - 1][start_y - 1][0] = 1
    dx = [0, 0, 1, -1]; dy = [1, -1, 0, 0]
    
    while queue:
        x, y, count, flag = queue.popleft()
        if (x, y) == (end_x - 1, end_y - 1): # loof end
            return count
        
        for i in range(4):
            new_x = x + dx[i]; new_y = y + dy[i]
            if 0 <= new_x < column and 0 <= new_y < row and check[new_x][new_y][flag] == 0:
                if flag == 0: # if not broke wall
                    if table[new_x][new_y] == 0:
                        queue.append((new_x, new_y, count + 1, flag))
                        check[new_x][new_y][flag] = 1
                    else:
                        queue.append((new_x, new_y, count + 1, flag + 1))
                        check[new_x][new_y][flag] = 1
                        check[new_x][new_y][flag + 1] = 1
                else: # if broke wall
                    if table[new_x][new_y] == 0:
                        queue.append((new_x, new_y, count + 1, flag))
                        check[new_x][new_y][flag] = 1

    return -1                
                    

column, row = map(int, sys.stdin.readline().split())
start_x, start_y = map(int, sys.stdin.readline().split())
end_x, end_y = map(int, sys.stdin.readline().split())
table = []
for i in range(column):
    table.append(list(map(int, sys.stdin.readline().split())))
    
print(bfs(start_x, start_y, end_x, end_y, column, row, table))