import sys

case = int(sys.stdin.readline())
for i in range(case):
    a, b = map(int, sys.stdin.readline().split(' '))
    print('Case #%d: %d + %d = %d' %(i + 1, a, b, a + b))