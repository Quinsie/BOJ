import sys
import math

case = 1
while True:
    info = list(map(int, sys.stdin.readline().split()))
    if info == [0]:
        break

    diagonal = math.sqrt((info[1] ** 2) + (info[2] ** 2))
    if diagonal > 2 * info[0]:
        print('Pizza %d does not fit on the table.' %(case))
    else:
        print('Pizza %d fits on the table.' %(case))
    case += 1