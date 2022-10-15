import sys

def eratos(n, k):
    table = [True] * (n + 1)
    table[0] = False; table[1] = False
    
    count = 0
    for i in range(2, n + 1):
        if table[i] == True:
            for j in range(i, n + 1, i):
                if table[j] == False:
                    continue
                else:
                    table[j] = False
                    count += 1
                    if count == k:
                        return j

n, k = map(int, sys.stdin.readline().split())
print(eratos(n, k))