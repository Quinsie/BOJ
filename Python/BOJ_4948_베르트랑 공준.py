import sys

def eratos(n):
    table = [True] * ((n * 2) + 1)
    table[0] = False; table[1] = False;
    for i in range(2, int(((n * 2) ** 0.5) + 1)):
        if table[i] == True:
            for j in range(i + i, (n * 2) + 1, i):
                table[j] = False
    
    arr = [k for k in range(n + 1, (n * 2) + 1) if table[k] == True]
    return len(arr)

while True:
    num = int(sys.stdin.readline())
    if num == 0:
        break
    print(eratos(num))