import sys

def recur(pos):
    if pos == n:
        if sum(temp) not in ans:
            ans.append(sum(temp))
        return
    
    for j in range(4):
        if table[j] < max(temp):
            continue
        temp[pos] = table[j]
        recur(pos + 1)
        temp[pos] = 0

n = int(sys.stdin.readline())
check = [False] * 4
table = [1, 5, 10, 50]
temp = [0 for _ in range(n)]
ans = []
recur(0)
print(len(ans))