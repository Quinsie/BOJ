import sys

case = int(sys.stdin.readline())
for i in range(case):
    x, y = map(int, sys.stdin.readline().split())
    if y != x and y != x - 2:
        print('No Number')
        continue

    if y == x:
        if x % 2 == 0:
            print((x // 2) * 4)
            continue
        else:
            print((x // 2) * 4 + 1)
            continue
    
    elif y == x - 2:
        if x % 2 == 0:
            print(((x - 1) // 2) * 4 + 2)
            continue
        else:
            print(((x - 2) // 2) * 4 + 3)