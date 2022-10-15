import sys

num = int(sys.stdin.readline())
for i in range(num):
    repeat, string = sys.stdin.readline().rstrip().split(' ')
    for k in string:
        print(k * int(repeat), end = '')
    print()