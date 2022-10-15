import sys

for i in range(3):
    tray = list(map(int, sys.stdin.readline().split(' ')))
    cnt = 0
    for j in tray:
        if j == 1:
            cnt += 1
    
    if cnt == 0:
        print('D')
    elif cnt == 1:
        print('C')
    elif cnt == 2:
        print('B')
    elif cnt == 3:
        print('A')
    else:
        print('E')