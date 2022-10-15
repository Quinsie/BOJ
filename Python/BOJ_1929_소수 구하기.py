import sys

def eratos(n, m):
    table = [True] * (m + 1)
    table[0] = False; table[1] = False
    for i in range(2, int((m ** 0.5) + 1)):
        if table[i] == True:
            for j in range(i + i, m + 1, i):
                table[j] = False
    
    return [k for k in range(n, m + 1) if table[k] == True]

start, end = map(int, sys.stdin.readline().split())
pm = eratos(start, end)

for i in pm:
    print(i)