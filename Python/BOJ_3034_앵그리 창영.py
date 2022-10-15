import sys

n, w, h = map(int, sys.stdin.readline().split(' '))
diagonal = ((w ** 2) + (h ** 2)) ** (1 / 2)
for i in range(n):
    temp = int(sys.stdin.readline())
    if temp <= diagonal:
        print('DA')
    else:
        print('NE')