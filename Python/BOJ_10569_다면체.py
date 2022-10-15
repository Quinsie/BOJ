import sys

num = int(sys.stdin.readline())
for i in range(num):
    v, e = map(int, sys.stdin.readline().split(' '))
    print(e + 2 - v)