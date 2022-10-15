import sys

case = int(sys.stdin.readline())
for i in range(case):
    temp = list(map(int, sys.stdin.readline().split()))
    temp.sort()
    print(temp[7])