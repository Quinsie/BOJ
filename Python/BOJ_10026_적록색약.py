import sys
import collections

def bfs(x, y, flag):
    queue = collections.deque()
    queue.append((x, y))
    
    dx = [1, -1, 0, 0]; dy = [0, 0, 1, -1]
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            new_x = x + dx[i]; new_y = y + dy[i]
            if 0 <= new_x < num and 0 <= new_y < num:
                if flag == 0: # 적록색약 아님, R만 지우기
                    if table_a[new_x][new_y] == 'R':
                        table_a[new_x][new_y] = 0
                        queue.append((new_x, new_y))
                elif flag == 1: # 적록색약 아님, G만 지우기
                    if table_a[new_x][new_y] == 'G':
                        table_a[new_x][new_y] = 0
                        queue.append((new_x, new_y))
                elif flag == 2: # 적록색약 아님, B만 지우기
                    if table_a[new_x][new_y] == 'B':
                        table_a[new_x][new_y] = 0
                        queue.append((new_x, new_y))
                elif flag == 3: # 적록색약임, R, G 모두 지우기
                    if table_b[new_x][new_y] == 'R' or table_b[new_x][new_y] == 'G':
                        table_b[new_x][new_y] = 0
                        queue.append((new_x, new_y))
                elif flag == 4:
                    if table_b[new_x][new_y] == 'B':
                        table_b[new_x][new_y] = 0
                        queue.append((new_x, new_y))
    

num = int(sys.stdin.readline())
table_a = [[] for _ in range(num)] # 적록색약 아닌 사람
table_b = [[] for _ in range(num)] # 적록색약인사람
for i in range(num):
     temp = sys.stdin.readline().rstrip()
     for j in temp:
         table_a[i].append(j)
         table_b[i].append(j)

count_a = 0; count_b = 0 
for a in range(num):
    for b in range(num):
        if table_a[a][b] == 'R': # 적록색약 아닌 지도에서 R이 나올 때
            bfs(a, b, 0) # flag = 0; R만 지우기
            count_a += 1
        elif table_a[a][b] == 'G': # 적록색약 아닌 지도에서 G가 나올 때
            bfs(a, b, 1) # flag = 1; G만 지우기
            count_a += 1
        elif table_a[a][b] == 'B':
            bfs(a, b, 2) # flag = 2; B만 지우기
            count_a += 1
        
        if table_b[a][b] == 'R' or table_b[a][b] == 'G': # 적록색약인 지도에서 R, G가 나올 때
            bfs(a, b, 3) # flag = 3; R, G 지우기
            count_b += 1
        elif table_b[a][b] == 'B':
            bfs(a, b, 4) # flag = 4; B 지우기. flag가 2인 경우와 비교하여 합쳐보기
            count_b += 1

print('%d %d' %(count_a, count_b))