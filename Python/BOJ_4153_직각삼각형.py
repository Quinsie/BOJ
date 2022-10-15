import sys

while True:
    temp = list(map(int, sys.stdin.readline().split(' ')))
    if sum(temp) == 0:
        break
    temp.sort()
    if (temp[0] ** 2) + (temp[1] ** 2) == (temp[2] ** 2):
        print('right')
    else:
        print('wrong')