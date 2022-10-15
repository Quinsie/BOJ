import sys

n, k = map(int, sys.stdin.readline().split())
check = [False] * (n + 1)
ans = [0 for i in range(n + 1)]

def recur(pos):
    if pos == k:
        for i in range(k):
            print(ans[i], end = ' ')
        print()
        return
    
    for num in range(1, n + 1):
        if check[num] == False:
            check[num] = True
            ans[pos] = num
            recur(pos + 1)
            check[num] = False
            
recur(0)