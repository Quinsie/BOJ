import sys
import collections

def bfs(building, start, end, up, down):
    queue = collections.deque()
    queue.append((start, 0))
    dx = [up, -down]
    check = [0 for _ in range(building)]
    check[start - 1] = 1

    while queue:
        loc, count = queue.popleft()
        if loc == end:
            return count
        for i in range(2):
            new_loc = loc + dx[i]
            if 0 < new_loc <= building and check[new_loc - 1] == 0:
                check[new_loc - 1] = 1
                queue.append((new_loc, count + 1))
    
    return 'use the stairs'

building, start, end, up, down = map(int, sys.stdin.readline().split())
print(bfs(building, start, end, up, down))