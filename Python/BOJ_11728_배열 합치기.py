import sys

size_1, size_2 = map(int, sys.stdin.readline().split())
arr_1 = list(map(int, sys.stdin.readline().split()))
arr_2 = list(map(int, sys.stdin.readline().split()))

arr = arr_1 + arr_2
arr.sort()
for i in arr:
    print(i, end = ' ')