import sys

def recur(pos):
    if sum(temp) > 100 or len(ans) != 0:
        return

    if pos == 7:
        if sum(temp) == 100:
            for i in temp:
                ans.append(i)
        return
    
    for j in range(9):
        if check[j] == False:
            check[j] = True
            temp.append(dwarf[j])
            recur(pos + 1)
            check[j] = False
            temp.pop()

dwarf = []
for i in range(9):
    dwarf.append(int(sys.stdin.readline()))

check = [False] * 9
temp = []
ans = []
recur(0)
ans.sort()
for j in ans:
    print(j)