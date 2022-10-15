import sys

n = int(sys.stdin.readline())

table = [[0,0,0] for _ in range(n)]

for i in range(n):
    temp = list(map(int, sys.stdin.readline().split()))
    if i == 0:
        table[0] = temp
    else:
        table[i][0] = min(table[i - 1][1], table[i - 1][2]) + temp[0]
        table[i][1] = min(table[i - 1][0], table[i - 1][2]) + temp[1]
        table[i][2] = min(table[i - 1][0], table[i - 1][1]) + temp[2]
        
print(min(table[n - 1]))