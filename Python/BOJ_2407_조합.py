import sys

def combination(n, r):
    if r > n // 2:
        r = n - r
    
    temp = r
    result = 1
    while temp > 0:
        result *= n
        n -= 1; temp -= 1
    
    while r > 0:
        result = result // r
        r -= 1
    
    return result

n, m = map(int, sys.stdin.readline().split())
print(combination(n, m))