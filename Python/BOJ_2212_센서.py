import sys

sensor = int(sys.stdin.readline())
center = int(sys.stdin.readline())

if center >= sensor:
    print(0)

else:
    coordinate = list(map(int, sys.stdin.readline().split()))
    coordinate.sort()

    distance = []
    for i in range(1, sensor):
        distance.append(coordinate[i] - coordinate[i - 1])

    distance.sort()
    for i in range(center - 1):
        distance.pop()

    print(sum(distance))