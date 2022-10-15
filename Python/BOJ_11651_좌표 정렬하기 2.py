import sys

num = int(sys.stdin.readline())
coordinate = []

for i in range(num):
    coordinate.append(list(map(int, sys.stdin.readline().split())))

coordinate.sort(key = lambda x : (x[1], x[0]))

for j in range(num):
    print('%d %d' %(coordinate[j][0], coordinate[j][1]))