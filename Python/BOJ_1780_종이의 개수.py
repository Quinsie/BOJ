import sys

def cut(x, y, length, arr):
    global minus, zero, plus
    start = arr[x][y]; count = 0
    for i in range(length):
        for j in range(length):
            if arr[x + i][y + j] != start:
                count += 1
            if count != 0:
                break
        if count != 0:
            break
    
    if count == 0:
        if start == -1:
            minus += 1
        elif start == 0:
            zero += 1
        else:
            plus += 1
    else:
        for j in range(9):
            new_length = length // 3
            new_x = x + (dx[j] * new_length)
            new_y = y + (dy[j] * new_length)
            cut(new_x, new_y, new_length, arr)

size = int(sys.stdin.readline())
table = []
for i in range(size):
    table.append(list(map(int, sys.stdin.readline().split())))

dx = [0, 0, 0, 1, 1, 1, 2, 2, 2]
dy = [0, 1, 2, 0, 1, 2, 0, 1, 2]

minus = 0; zero = 0; plus = 0
cut(0, 0, size, table)
print("%d\n%d\n%d" %(minus, zero, plus))