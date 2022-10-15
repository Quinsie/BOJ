import sys

n, m = map(int, sys.stdin.readline().split())
count = 0
arr = []
for i in range(n):
    arr.append(sys.stdin.readline().rstrip())
arr = set(arr)
for j in range(m):
    string = sys.stdin.readline().rstrip()
    if string in arr:
        count += 1
print(count)