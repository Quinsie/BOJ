import sys
import collections

def bfs(x, y, count):
    queue = collections.deque()
    queue.append((x, y, count))

    while queue:
        x, y, count = queue.popleft()

        if (x, y) == (end_x, end_y):
            print(count)
            return

        for i in range(8):
            new_x = x + dx[i]; new_y = y + dy[i]
            if 0 <= new_x < size and 0 <= new_y < size and table[new_x][new_y] == 0:
                table[new_x][new_y] = 1
                queue.append((new_x, new_y, count + 1))

case = int(sys.stdin.readline())
for i in range(case):
    size = int(sys.stdin.readline())
    table = [[0 for _ in range(size)] for _ in range(size)]
    start_x, start_y = map(int, sys.stdin.readline().split())
    end_x, end_y = map(int, sys.stdin.readline().split())
    dx = [1, 1, 2, 2, -1, -1, -2, -2]
    dy = [-2, 2, -1, 1, -2, 2, -1, 1]
    bfs(start_x, start_y, 0)