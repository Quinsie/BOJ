import sys

case = int(sys.stdin.readline())
for i in range(case):
    house_num = int(sys.stdin.readline())
    house = list(map(int, sys.stdin.readline().split()))

    destroy = 0
    for j in range(len(house) - 1):
        if house[j] >= house[j + 1]:
            destroy += 1

    print("Case #%d: %d" %(i + 1, destroy))