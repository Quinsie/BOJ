import sys

n, m = map(int, sys.stdin.readline().split())
check = [False] * (n + 1)
ans = [0 for _ in range(m + 1)]

def recur(pos):
    if pos == m:
        for i in range(m):
            print(ans[i], end = ' ')
        print()
        return
    
    for num in range(max(ans) + 1, n + 1):
        if check[num] == False:
            check[num] = True
            ans[pos] = num
            recur(pos + 1)
            check[num] = False
            ans[pos] = 0
            
recur(0)