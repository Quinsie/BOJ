import sys

n, m = map(int, sys.stdin.readline().split())
num_list = list(map(int, sys.stdin.readline().split()))
num_list.sort()
ans = [0 for _ in range(m)]

def recur(pos):
    if pos == m:
        for i in range(m):
            print(ans[i], end = ' ')
        print()
        return
    
    temp = 0
    for j in range(n):
        if num_list[j] < max(ans):
            continue
        if temp != num_list[j]:
            ans[pos] = num_list[j]
            temp = num_list[j]
            recur(pos + 1)
            ans[pos] = 0
            
recur(0)