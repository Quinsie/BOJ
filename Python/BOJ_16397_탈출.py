import sys
import collections

def bfs(num, max_click, target):
    queue = collections.deque()
    queue.append((num, 0))
    check = [0 for _ in range(100000)]
    check[num] = 1
    
    while queue:
        loc, count = queue.popleft()
        if count > max_click:
            return 'ANG'
        if count <= max_click and loc == target:
            return count
        
        if 0 <= loc + 1 < 100000 and check[loc + 1] == 0:
            check[loc + 1] = 1
            queue.append((loc + 1, count + 1))
        
        if 0 <= loc * 2 < 100000:
            temp = str(loc * 2)
            if int(temp) != 0:
                temp = str(int(temp[0]) - 1) + temp[1:]
            if check[int(temp)] == 0:
                check[int(temp)] = 1
                queue.append((int(temp), count + 1))
                
    return 'ANG'       

num, max_click, target = map(int, sys.stdin.readline().split())
print(bfs(num, max_click, target))    