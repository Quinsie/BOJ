import sys

n, m = map(int, sys.stdin.readline().split())
ans = [1 for _ in range(m + 1)]

def recur(pos):
    if pos == m:
        for i in range(m):
            print(ans[i], end = ' ')
        print()
        return
    
    for num in range(max(ans), n + 1):
        ans[pos] = num
        recur(pos + 1)
        ans[pos] = 1
            
recur(0)