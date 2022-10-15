import sys

def recur(pos):
    global ans

    if sum(temp) > target:
        return
    if pos == 3:
        if abs(target - sum(temp)) < abs(target - ans):
            ans = sum(temp)
        return
    
    for i in range(card):
        if card_list[i] < max(temp):
            continue
        if check[i] == False:
            check[i] = True
            temp[pos] = card_list[i]
            recur(pos + 1)
            check[i] = False
            temp[pos] = 0

card, target = map(int, sys.stdin.readline().split())
card_list = list(map(int, sys.stdin.readline().split()))
card_list.sort()

check = [False] * card
temp = [0 for _ in range(3)]
ans = 0
recur(0)
print(ans)