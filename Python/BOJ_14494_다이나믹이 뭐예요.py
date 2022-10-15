import sys

def arrsum_mod(arr, mod):
    temp = 0
    for i in arr:
        temp += i % mod
    return temp % mod

n, m = map(int, sys.stdin.readline().split())

table = [[1 for _ in range(m)]]
for a in range(n - 1):
    temp = [1]
    for b in range(m - 1):
        temp.append(0)
    table.append(temp)

for i in range(1, n):
    for j in range(1, m):
        table[i][j] = arrsum_mod([table[i - 1][j], table[i][j - 1], table[i - 1][j - 1]], (10 ** 9) + 7)

print(table[n - 1][m - 1])