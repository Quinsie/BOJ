import sys

num = int(sys.stdin.readline())
count = 1
while count <= num:
    print(' ' * (num - count), end = '')
    print('*' * (1 + (2 * (count - 1))))
    count += 1

count -= 2
while count > 0:
    print(' ' * (num - count), end = '')
    print('*' * (1 + (2 * (count - 1))))
    count -= 1