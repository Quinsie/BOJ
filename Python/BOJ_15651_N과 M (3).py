import sys

n, m = map(int, sys.stdin.readline().split())
ans = [0 for _ in range(m + 1)]

def recur(pos):
    if pos == m:
        for i in range(m):
            print(ans[i], end = ' ')
        print()
        return
    
    for num in range(1, n + 1):
        ans[pos] = num
        recur(pos + 1)
            
recur(0)