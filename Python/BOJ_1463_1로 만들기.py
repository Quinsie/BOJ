import sys
import collections

def bfs():
    queue = collections.deque()
    queue.append((1, 0))
    check = [0 for _ in range(1000001)]

    while queue:
        now, count = queue.popleft()

        if 0 < now + 1 <= 10e5 and check[now + 1] == 0:
            check[now + 1] = count + 1
            queue.append((now + 1, count + 1))
        if 0 < now * 2 <= 10e5 and check[now * 2] == 0:
            check[now * 2] = count + 1
            queue.append((now * 2, count + 1))
        if 0 < now * 3 <= 10e5 and check[now * 3] == 0:
            check[now * 3] = count + 1
            queue.append((now * 3, count + 1))
    
    return check

num = int(sys.stdin.readline())
arr = bfs()
print(arr[num])