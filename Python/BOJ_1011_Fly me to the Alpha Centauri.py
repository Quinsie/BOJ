import sys

case = int(sys.stdin.readline())
for i in range(case):
    start, end = map(int, sys.stdin.readline().split())
    length = end - start
    
    total = 0; count = 1
    while length > total * 2:
        total += count
        count += 1
    
    mid = ((count * (count - 1)) + ((count - 1) * (count - 2)) + 1) / 2
    if length < mid:
        print(count + (count - 3))
    else:
        print(count + (count - 2))