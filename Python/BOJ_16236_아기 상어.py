import sys
import collections

def bfs(count, x, y, shark, food):
    queue = collections.deque()
    queue.append((count, x, y, shark, food))
    dx = [-1, 0, 0, 1]; dy = [0, -1, 1, 0]

    check = [[0 for _ in range(size)] for _ in range(size)]
    check[x][y] = 1
    table[x][y] = 0
    time = 0
    while queue:
        queue = collections.deque(sorted(queue))
        count, x, y, shark, food = queue.popleft()
        
        if 0 < table[x][y] < shark:
            table[x][y] = 0
            check = [[0 for _ in range(size)] for _ in range(size)]
            queue = collections.deque()
            food += 1
            if food == shark:
                food = 0
                shark += 1
            time += count
            queue.append((0, x, y, shark, food))
            check[x][y] = 1
            continue

        for i in range(4):
            new_x = x + dx[i]; new_y = y + dy[i]
            if 0 <= new_x < size and 0 <= new_y < size:
                if table[new_x][new_y] <= shark and check[new_x][new_y] == 0:
                    check[new_x][new_y] = 1
                    queue.append((count + 1, new_x, new_y, shark, food))
        
    return time

size = int(sys.stdin.readline())
table = []
for i in range(size):
    table.append(list(map(int, sys.stdin.readline().split())))

for a in range(size):
    for b in range(size):
        if table[a][b] == 9:
            start_x, start_y = a, b

print(bfs(0, start_x, start_y, 2, 0))