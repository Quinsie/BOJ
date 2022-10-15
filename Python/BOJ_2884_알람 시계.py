import sys

hr, min = map(int, sys.stdin.readline().split(' '))

min -= 45
if min < 0:
    hr -= 1
    min += 60
if hr < 0:
    hr += 24
print('%d %d' %(hr, min))