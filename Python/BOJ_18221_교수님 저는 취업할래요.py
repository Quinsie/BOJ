import sys
import math

size = int(sys.stdin.readline())
table = []
for i in range(size):
    table.append(list(map(int, sys.stdin.readline().split())))

professor = (0, 0)
student = (0, 0)
for j in range(size):
    for k in range(size):
        if table[j][k] == 5:
            professor = (j, k)
        if table[j][k] == 2:
            student = (j, k)

zone_x1 = min(professor[0], student[0])
zone_y1 = min(professor[1], student[1])
zone_x2 = max(professor[0], student[0])
zone_y2 = max(professor[1], student[1])

count = 0
for m in range(zone_x1, zone_x2 + 1):
    for n in range(zone_y1, zone_y2 + 1):
        if table[m][n] == 1:
            count += 1

distance = math.sqrt(pow(student[0] - professor[0], 2) + pow(student[1] - professor[1], 2))

if distance >= 5 and count >= 3:
    print(1)
else:
    print(0)