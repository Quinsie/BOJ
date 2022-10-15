import sys

def eratos(n, m):
    table = [True] * (m + 1)
    table[0] = False; table[1] = False

    for i in range(2, int(m ** 0.5) + 1):
        if table[i] == True:
            for j in range(i + i, m + 1, i):
                table[j] = False
    
    return [str(k) for k in range(n, m + 1) if table[k] == True]

a, b, d = map(int, sys.stdin.readline().split())
arr = eratos(a, b)

count = 0
for i in arr:
    for j in i:
        if j == str(d):
            count += 1
            break

print(count)