import sys
import collections

def bfs(x, y, target, table, column, row):
    queue = collections.deque()
    queue.append((x, y, 0, '1')) # x, y, count, now_num
    dx = [0, 0, 1, -1]; dy = [1, -1, 0, 0]
    check = [[0 for _ in range(row)] for _ in range(column)]
    check[x][y] = 1

    saved_count = 0
    while queue:
        x, y, count, now_num = queue.popleft()
        if table[x][y] == now_num:
            saved_count += count
            now_num = str(int(now_num) + 1)
            queue = collections.deque()
            queue.append((x, y, 0, now_num))
            check = [[0 for _ in range(row)] for _ in range(column)]
            if int(now_num) > target:
                return saved_count
            continue

        for i in range(4):
            new_x = x + dx[i]; new_y = y + dy[i]
            if 0 <= new_x < column and 0 <= new_y < row:
                if check[new_x][new_y] == 0 and table[new_x][new_y] != 'X':
                    check[new_x][new_y] = 1
                    queue.append((new_x, new_y, count + 1, now_num))

column, row, num = map(int, sys.stdin.readline().split())
table = [[] for _ in range(column)]

for i in range(column):
    temp = sys.stdin.readline().rstrip()
    for j in range(row):
        if temp[j] == 'S':
            start_x = i; start_y = j
            table[i].append('.')
            continue
        table[i].append(temp[j])

print(bfs(start_x, start_y, num, table, column, row))