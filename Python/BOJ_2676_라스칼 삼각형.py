import sys

case = int(sys.stdin.readline())
for i in range(case):
    n, m = map(int, sys.stdin.readline().split())
    print(1 + m * (n - m))