import sys

table = [[0 for _ in range(100)] for _ in range(100)]
paper = int(sys.stdin.readline())
for n in range(paper):
    x, y = map(int, sys.stdin.readline().split())
    for a in range(x - 1, x + 9):
        for b in range(y - 1, y + 9):
            if table[a][b] == 0:
                table[a][b] = 1

count = 0
for i in range(100):
    for j in range(100):
        if table[i][j] == 1:
            count += 1

print(count)