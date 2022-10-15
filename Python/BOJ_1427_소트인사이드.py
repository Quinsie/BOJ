import sys

num = sys.stdin.readline().rstrip()
arr = []
for i in num:
    int(i)
    arr.append(i)

arr.sort(reverse=True)
for j in arr:
    print(j, end = '')