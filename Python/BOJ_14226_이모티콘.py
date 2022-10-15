import sys
import collections

def bfs(target):
    queue = collections.deque()
    queue.append((1, 0, 0))
    check = [[] for _ in range(2000)]
    check[1].append(0)

    while queue:
        now, time, clipboard = queue.popleft()
        if now == target:
            print(time)
            return

        if 0 < now - 1 < 2000 and clipboard not in check[now - 1]:
            check[now - 1].append(clipboard)
            queue.append((now - 1, time + 1, clipboard))
        if 0 < now + clipboard < 2000 and clipboard not in check[now + clipboard]:
            check[now + clipboard].append(clipboard)
            queue.append((now + clipboard, time + 1, clipboard))
        if now not in check[now]:
            check[now].append(now)
            queue.append((now, time + 1, now))
        

target = int(sys.stdin.readline())
bfs(target)