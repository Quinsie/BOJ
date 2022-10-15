import sys

table = []
for i in range(3):
    table.append(list(map(int, sys.stdin.readline().split())))

if table[0][0] == table[1][0]:
    x = table[2][0]
else:
    if table[0][0] == table[2][0]:
        x = table[1][0]
    else:
        x = table[0][0]

if table[0][1] == table[1][1]:
    y = table[2][1]
else:
    if table[0][1] == table[2][1]:
        y = table[1][1]
    else:
        y = table[0][1]

print(x, y)