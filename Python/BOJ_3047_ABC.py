import sys

num = list(map(int, sys.stdin.readline().split()))
order = sys.stdin.readline().rstrip()

for i in order:
    if i == 'A':
        print(min(num), end = ' ')
    elif i == 'C':
        print(max(num), end = ' ')
    else:
        temp = sorted(num)
        print(temp[1], end = ' ')