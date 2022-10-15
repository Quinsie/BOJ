import sys

have, need = map(int, sys.stdin.readline().split())
have_list = []
for a in range(have):
    have_list.append(int(sys.stdin.readline()))

left, right = 1, max(have_list)
while left <= right:
    mid = (left + right) // 2
    sum = 0

    for i in have_list:
        sum += i // mid
    
    if sum >= need:
        left = mid + 1
    else:
        right = mid - 1

print(right)