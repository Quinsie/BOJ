import sys

def eratos(n):
    table = [True] * (n + 1)
    table[0] = False; table[1] = False

    for i in range(2, int(n ** 0.5) + 1):
        if table[i] == True:
            for j in range(i + i, n + 1, i):
                table[j] = False
    
    return table

case = int(sys.stdin.readline())
for i in range(case):
    a = int(sys.stdin.readline())
    b = a // 2
    arr = eratos(a)

    for j in range(b, 1, -1):
        if arr[a - j] == True and arr[j] == True:
            print("%d %d" %(j, a - j))
            break