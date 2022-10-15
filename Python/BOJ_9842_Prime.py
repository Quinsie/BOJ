import sys

def eratos():
    table = [True] * (105000 + 1)
    table[0] = False; table[1] = False

    for i in range(2, int(105000 ** 0.5) + 1):
        if table[i] == True:
            for j in range(i + i, 105000 + 1, i):
                table[j] = False
    
    return [k for k in range(105000 + 1) if table[k] == True]

num = int(sys.stdin.readline())
arr = eratos()
print(arr[num - 1])