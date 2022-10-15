import sys

def step(x, y):
    global maximum
    queue = set([(x, y, table[x][y])])

    while queue:
        x, y, char = queue.pop()

        for i in range(4):
            new_x = x + dx[i]; new_y = y + dy[i]
            if 0 <= new_x < row and 0 <= new_y < column and table[new_x][new_y] not in char:
                queue.add((new_x, new_y, char + table[new_x][new_y]))
                if len(char) + 1 > maximum:
                    maximum = len(char) + 1
    
row, column = map(int, sys.stdin.readline().split())
table = []
for i in range(row):
    table.append(sys.stdin.readline().rstrip())

maximum = 1
dx = [1, -1, 0, 0]; dy = [0, 0, 1, -1]
step(0, 0)
print(maximum)