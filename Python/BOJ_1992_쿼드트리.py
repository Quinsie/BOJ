import sys

def compress(x, y, length, arr):
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
        print(start, end = '')
    else:
        print('(', end = '')
        compress(x, y, length // 2, arr)
        compress(x, y + (length // 2), length // 2, arr)
        compress(x + (length // 2), y, length // 2, arr)
        compress(x + (length // 2), y + (length // 2), length // 2, arr)
        print(')', end = '')
    return


size = int(sys.stdin.readline())
table = []
for i in range(size):
    table.append(sys.stdin.readline().rstrip())

compress(0, 0, size, table)