import sys

num = int(sys.stdin.readline())
for i in range(1, num + 1):
    print('*' * i, end = '')
    print(' ' * ((num - i) * 2), end = '')
    print('*' * i)

for j in range(num - 1, 0, -1):
    print('*' * j, end = '')
    print(' ' * ((num - j) * 2), end = '')
    print('*' * j)