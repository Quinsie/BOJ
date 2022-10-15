import sys

num = int(sys.stdin.readline())
for i in range(num):
    case = list(map(int, sys.stdin.readline().split(' ')))
    avr = sum(case[1:]) / case[0]
    cnt = 0
    for j in range(1, len(case)):
        if case[j] > avr:
            cnt += 1
    print('%.3f' %(round(cnt / case[0] * 100, 3)), end = '%\n')