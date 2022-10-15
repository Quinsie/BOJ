import sys

num = int(sys.stdin.readline())
for i in range(num):
    temp1 = int(sys.stdin.readline())
    temp2 = list(map(int, sys.stdin.readline().split(' ')))
    if sum(temp2) > 0:
        print('Right')
    elif sum(temp2) == 0:
        print('Equilibrium')
    else:
        print('Left')