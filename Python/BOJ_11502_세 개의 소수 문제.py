import sys

def eratos(n):
    table = [True] * (n + 1)
    table[0] = False; table[1] = False

    for i in range(2, int(n ** 0.5) + 1):
        if table[i] == True:
            for j in range(i + i, n + 1, i):
                table[j] = False
    
    return [k for k in range(n + 1) if table[k] == True]

def recur(pos):
    if len(ans) != 0:
        return 
        
    if pos == 3:
        if len(ans) == 0:
            if sum(temp) == num:
                for i in range(3):
                    ans.append(temp[i])
        return
    
    for j in range(len(pm_num)):
        if pm_num[j] < max(temp):
            continue
        temp[pos] = pm_num[j]
        recur(pos + 1)
        temp[pos] = 0

case = int(sys.stdin.readline())
for i in range(case):
    num = int(sys.stdin.readline())

    pm_num = eratos(num)
    temp = [0 for _ in range(3)]
    ans = []
    recur(0)
    if len(ans) > 0:
        for j in ans:
            print(j, end = ' ')
        print()
    else:
        print(0)