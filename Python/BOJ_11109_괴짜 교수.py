import sys

num = int(sys.stdin.readline())
for i in range(num):
    d, n, s, p = map(int, sys.stdin.readline().split(' '))
    series = n * s; parallel = d + (n * p)
    if parallel > series:
        print('do not parallelize')
    elif parallel < series:
        print('parallelize')
    else:
        print('does not matter')