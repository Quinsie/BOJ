import sys

case = int(sys.stdin.readline())

for i in range(case):
    s = []
    n = int(sys.stdin.readline())
    for k in range(2):
        s.append(list(map(int, sys.stdin.readline().split())))
    for j in range(1, n):
        if j == 1:
            s[0][j] += s[1][j - 1]
            s[1][j] += s[0][j - 1]
        else:
            s[0][j] += max(s[1][j - 1], s[1][j - 2])
            s[1][j] += max(s[0][j - 1], s[0][j - 2])
            
    print(max(s[0][n - 1], s[1][n - 1]))