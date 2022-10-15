import sys

def recur(pos):
    if pos == 6:
        for i in range(6):
            print(ans[i], end = ' ')
        print()
        return
    
    for j in range(len(num_list)):
        if num_list[j] < max(ans):
            continue
        if check[j] == False:
            check[j] = True
            ans[pos] = num_list[j]
            recur(pos + 1)
            check[j] = False
            ans[pos] = 0

while True:
    n = list(map(int, sys.stdin.readline().split()))
    if n[0] == 0:
        break

    num_list = n[1:]
    num_list.sort()
    n = n[0]

    check = [False] * (len(num_list) + 1)
    ans = [0 for _ in range(6)]

    recur(0)
    print()