import sys

num = int(sys.stdin.readline())
for i in range(num):
    temp = list(map(int, sys.stdin.readline().split()))
    temp = sorted(temp[1:])

    big = max(temp); small = min(temp); gap = 0
    for j in range(1, len(temp)):
        if temp[j] - temp[j - 1] > gap:
            gap = temp[j] - temp[j - 1]
    
    print('Class %d' %(i + 1))
    print('Max %d, Min %d, Largest gap %d' %(big, small, gap))