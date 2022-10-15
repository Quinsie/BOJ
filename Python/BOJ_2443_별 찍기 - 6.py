import sys

num = int(sys.stdin.readline())
for i in range(num, 0, -1):
    print(' ' * (num - i), end = '')
    print('*' * (1 + (2 * (i - 1))))
