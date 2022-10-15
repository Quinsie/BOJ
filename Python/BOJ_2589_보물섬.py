import sys
import collections

def bfs(x, y, count):
    queue = collections.deque()
    queue.append((x, y, count))

    check = [[0 for _ in range(row)] for _ in range(column)]
    check[x][y] = 1
    longest = 0
    while queue:
        x, y, count = queue.popleft()        
        for i in range(4):
            new_x = x + dx[i]; new_y = y + dy[i]
            if 0 <= new_x < column and 0 <= new_y < row:
                if table[new_x][new_y] == 'L' and check[new_x][new_y] == 0:
                    check[new_x][new_y] = 1
                    if count + 1 > longest:
                        longest = count + 1
                    queue.append((new_x, new_y, count + 1))
    
    return longest

column, row = map(int, sys.stdin.readline().split())
table = [[] for _ in range(column)]
for a in range(column):
    temp = sys.stdin.readline().rstrip()
    for b in temp:
        table[a].append(b)

dx = [-1, 1, 0, 0]; dy = [0, 0, 1, -1]

maximum = 0
for c in range(column):
    for d in range(row):
        if table[c][d] == 'L':
            temp = bfs(c, d, 0)
            if temp > maximum:
                maximum = temp

print(maximum)