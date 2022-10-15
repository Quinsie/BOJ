import sys

def eratos(n, m):
    table = [True] * (int(m ** 0.5) + 1)
    table[0] = False; table[1] = False
    for i in range(2, int((m ** 0.5) + 1)):
        if table[i] == True:
            for j in range(i + i, (int(m ** 0.5) + 1), i):
                table[j] = False

    count = 0
    for l in [k for k in range(int(m ** 0.5) + 1) if table[k] == True]:
        pow = 2
        while (l ** pow) <= m:
            if (l ** pow) >= n:
                count += 1
            pow += 1
    return count

start, end = map(int, sys.stdin.readline().split())
print(eratos(start, end))