import sys
import collections

def bfs(a, b, loc, end, count):
    queue = collections.deque()
    queue.append((loc, count))
    check = [0 for _ in range(100001)]
    check[loc] = 1
    minimum = 100001
    dx = [a, b, -a, -b, 1, -1]

    while queue:
        loc, count = queue.popleft()
        if loc == end and count < minimum:
            return count
        
        for i in range(2):
            new_loc = loc * dx[i]
            if 0 <= new_loc <= 100000 and check[new_loc] == 0:
                check[new_loc] = 1
                queue.append((new_loc, count + 1))
        for j in range(6):
            new_loc = loc + dx[j]
            if 0 <= new_loc <= 100000 and check[new_loc] == 0:
                check[new_loc] = 1
                queue.append((new_loc, count + 1))
    
    return -1

a, b, start, end = map(int, sys.stdin.readline().split())
print(bfs(a, b, start, end, 0))