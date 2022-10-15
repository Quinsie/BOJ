import sys

x, y = map(int, sys.stdin.readline().split())
month = [[1, 3, 5, 7, 8, 10, 12], [4, 6, 9, 11], [2]]

for i in range(1, x):
    if i in month[0]:
        y += 31
    elif i in month[1]:
        y += 30
    elif i in month[2]:
        y += 28

if y % 7 == 1:
    print('MON')
elif y % 7 == 2:
    print('TUE')
elif y % 7 == 3:
    print('WED')
elif y % 7 == 4:
    print('THU')
elif y % 7 == 5:
    print('FRI')
elif y % 7 == 6:
    print('SAT')
else:
    print('SUN')