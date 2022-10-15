import sys

coordinate = []
for i in range(3):
    temp = list(map(int, sys.stdin.readline().split()))
    coordinate.append(temp)

if coordinate[0][0] == coordinate[1][0]:    # y축과 평행한 경우
    if coordinate[0][0] == coordinate[2][0]:
        print('WHERE IS MY CHICKEN?')
    else:
        print('WINNER WINNER CHICKEN DINNER!')

else:
    slope = (coordinate[1][1] - coordinate[0][1]) / (coordinate[1][0] - coordinate[0][0])
    if coordinate[2][1] == slope * (coordinate[2][0] - coordinate[0][0]) + coordinate[0][1]:
        print('WHERE IS MY CHICKEN?')
    else:
        print('WINNER WINNER CHICKEN DINNER!')