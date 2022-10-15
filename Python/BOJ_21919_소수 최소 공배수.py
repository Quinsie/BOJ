import sys

def eratos(n, m):
    table = [True] * (m + 1)
    table[0] = False; table[1] = False

    for i in range(2, int(m ** 0.5) + 1):
        if table[i] == True:
            for j in range(i + i, m + 1, i):
                table[j] = False
    
    return [k for k in range(n, m + 1) if table[k] == True]

def gcd(x, y):
    a = max(x, y); b = min(x, y)
    while b != 0:
        temp = a
        a = b
        b = temp % a
    return a

def lcm(x, y):
    return (x * y) // gcd(x, y)

def lcm_arr(arr):
    lcm_now = arr[0]
    for i in range(1, len(arr)):
        lcm_now = lcm(lcm_now, arr[i])
    return lcm_now

num = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
eratos_arr = eratos(min(arr), max(arr))
pm = []
for i in arr:
    if i in eratos_arr:
        pm.append(i)

if len(pm) > 0:
    print(lcm_arr(pm))
else:
    print(-1)