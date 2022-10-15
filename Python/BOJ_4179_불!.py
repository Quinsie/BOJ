import sys
import collections

def bfs(chart):
    queue = collections.deque()
    for i in fire:
        queue.append(i)
    queue.append((start_x, start_y, 0, 0)) # 4번째 변수 = 0이면 지훈 (flag)
    dx = [1, -1, 0, 0]; dy = [0, 0, 1, -1]
    check = [[0 for _ in range(row)] for _ in range(column)]
    check[start_x][start_y] = 1

    while queue:
        x, y, count, flag = queue.popleft()
        for i in range(4):
            new_x = x + dx[i]; new_y = y + dy[i]
            if new_x < 0 or new_x >= column or new_y < 0 or new_y >= row: # 지도 가장자리에 있을 때
                if flag == 0: # 그게 지훈이면 반환
                    return count + 1
            elif 0 <= new_x < column and 0 <= new_y < row:
                if flag == 0: # 지훈이일 경우
                    if chart[new_x][new_y] == '.' and check[new_x][new_y] == 0:
                        check[new_x][new_y] = 1
                        queue.append((new_x, new_y, count + 1, flag))
                else: # 불일 경우
                    if chart[new_x][new_y] == '.':
                        chart[new_x][new_y] = 'F'
                        queue.append((new_x, new_y, 0, flag))
    
    return 'IMPOSSIBLE'

column, row = map(int, sys.stdin.readline().split())
table = [[] for _ in range(column)]
fire = []
for i in range(column):
    temp = sys.stdin.readline().rstrip()
    for j in range(row):
        if temp[j] == 'J':
            start_x = i; start_y = j
            table[i].append('.')
            continue
        elif temp[j] == 'F':
            fire.append((i, j, 0, 1)) # 4번째 변수 = 1이면 불 (flag)
        table[i].append(temp[j])

print(bfs(table))