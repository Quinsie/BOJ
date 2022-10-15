import sys

num = int(sys.stdin.readline())
for i in range(num):
    r, e, c = map(int, sys.stdin.readline().split(' '))
    if (e - c) > r:
        print('advertise')
    elif (e - c) < r:
        print('do not advertise')
    else:
        print('does not matter')