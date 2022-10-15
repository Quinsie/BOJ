import sys

case = int(sys.stdin.readline())
for i in range(case):
    start, end = map(int, sys.stdin.readline().split())
    
    zero = 0
    while start <= end:
        start = str(start)
        for i in start:
            if i == '0':
                zero += 1
        start = int(start) + 1
    
    print(zero)