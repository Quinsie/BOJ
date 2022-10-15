import sys

def dfs(start):
    check[start - 1] = True
    print(start, end = ' ')

    for i in table[start - 1]:
        if check[i - 1] == False:
            dfs(i)

def bfs(start):
    queue = []
    queue.append(start)
    check[start - 1] = True

    while queue:
        now = queue[0]
        print(now, end = ' ')
        del queue[0]

        for i in table[now - 1]:
            if check[i - 1] == False:
                check[i - 1] = True
                queue.append(i)

point, line, start = map(int, sys.stdin.readline().split())
table = [[] for _ in range(point)]
for i in range(line):
    a, b = map(int, sys.stdin.readline().split())
    table[a - 1].append(b)
    table[b - 1].append(a)

for j in range(point):
    table[j].sort()

check = [False] * point
dfs(start)
print()
check = [False] * point
bfs(start)