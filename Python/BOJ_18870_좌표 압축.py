import sys

point = int(sys.stdin.readline())
point_list = list(map(int, sys.stdin.readline().split()))
point_list_two = sorted(list(set(point_list)))

dic = {point_list_two[i] : i for i in range(len(point_list_two))}
for i in point_list:
    print(dic[i], end = ' ')