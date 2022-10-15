import sys

def cut(x, y, length, arr):
    global white_paper, blue_paper
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
        if start == 0:
            white_paper += 1
        else:
            blue_paper += 1
    else:
        cut(x, y, length // 2, arr)
        cut(x, y + (length // 2), length // 2, arr)
        cut(x + (length // 2), y, length // 2, arr)
        cut(x + (length // 2), y + (length // 2), length // 2, arr)

size = int(sys.stdin.readline())
table = []
for i in range(size):
    table.append(list(map(int, sys.stdin.readline().split())))

white_paper = 0; blue_paper = 0
cut(0, 0, size, table)
print("%d\n%d" %(white_paper, blue_paper))