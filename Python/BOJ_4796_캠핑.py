import sys

case = 1
while True:
    l, p, v = map(int, sys.stdin.readline().split())
    if (l, p, v) == (0, 0, 0):
        break

    day = 0
    day += (v // p) * l

    if v % p >= l:
        day += l
    else:
        day += v % p
    
    print('Case %d: %d' %(case, day))
    case += 1