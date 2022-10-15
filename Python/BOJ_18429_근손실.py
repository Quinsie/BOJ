import sys

def recur(pos):
    global count
    global target

    if target < 500:
        return

    if pos == kit:
        count += 1
        return
    
    for j in range(kit):
        if check[j] == False:
            check[j] = True
            target += plus_muscle[j]
            recur(pos + 1)
            check[j] = False
            target -= plus_muscle[j]

kit, minus_muscle = map(int, sys.stdin.readline().split())
plus_muscle = list(map(int, sys.stdin.readline().split()))
for i in range(kit):
    plus_muscle[i] -= minus_muscle

check = [False] * kit
target = 500
count = 0
recur(0)
print(count)