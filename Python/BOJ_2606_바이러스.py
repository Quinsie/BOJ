import sys

def bfs(start):
    queue = []
    queue.append(start)
    check[start - 1] = True

    count = -1
    while queue:
        now = queue[0]
        count += 1
        del queue[0]

        for i in table[now - 1]:
            if check[i - 1] == False:
                check[i - 1] = True
                queue.append(i)
    
    print(count)

computer = int(sys.stdin.readline())
line = int(sys.stdin.readline())
table = [[] for _ in range(computer)]
for i in range(line):
    a, b = map(int, sys.stdin.readline().split())
    table[a - 1].append(b)
    table[b - 1].append(a)
for j in range(computer):
    table[j].sort()

check = [False] * computer
bfs(1)