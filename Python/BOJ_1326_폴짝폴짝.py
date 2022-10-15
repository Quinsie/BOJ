import sys
import collections

def bfs(loc, count, point, end):
    queue = collections.deque()
    queue.append((loc, count))
    check = [0 for _ in range(point)]
    check[loc] = 1

    while queue:
        loc, count = queue.popleft()
        if loc == end:
            return count
        for i in range(loc, point, table[loc]):
            if check[i] == 0:
                check[i] = 1
                queue.append((i, count + 1))
        for j in range(loc, -1, -table[loc]):
            if check[j] == 0:
                check[j] = 1
                queue.append((j, count + 1))

    return -1

point = int(sys.stdin.readline())
table = list(map(int, sys.stdin.readline().split()))
start, end = map(int, sys.stdin.readline().split())
print(bfs(start - 1, 0, point, end - 1))