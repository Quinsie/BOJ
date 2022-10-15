import sys
import collections

def bfs(start, end):
    queue = collections.deque()
    queue.append((start, 0, str(start)))
    check = [0 for _ in range(100001)]
    check[start] = 1
    dx = [1, -1, 2]
    
    while queue:
        loc, count, record = queue.popleft()
        if loc == end:
            print(count)
            print(record)
            return
        
        for i in range(3):
            if i < 2:
                new_loc = loc + dx[i]
            else:
                new_loc = loc * dx[i]
            
            if 0 <= new_loc < 100001 and check[new_loc] == 0:
                check[new_loc] = 1
                queue.append((new_loc, count + 1, record + ' ' + str(new_loc)))

start, end = map(int, sys.stdin.readline().split())
bfs(start, end)