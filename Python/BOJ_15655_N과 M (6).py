import sys

n, m = map(int, sys.stdin.readline().split())
num_list = list(map(int, sys.stdin.readline().split()))
num_list.sort()
check = [False] * (n + 1)
ans = [0 for _ in range(m + 1)]

def recur(pos):
    if pos == m:
        for i in range(m):
            print(ans[i], end = ' ')
        print()
        return
    
    for j in range(n):
        if num_list[j] < max(ans):
            continue
        if check[j] == False:
            check[j] = True
            ans[pos] = num_list[j]
            recur(pos + 1)
            check[j] = False
            ans[pos] = 0
            
recur(0)