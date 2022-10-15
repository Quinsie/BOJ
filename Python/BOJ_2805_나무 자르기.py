import sys
import collections

tree, need = map(int, sys.stdin.readline().split())
tree_list = collections.Counter(map(int, sys.stdin.readline().split()))

left = 0; right = max(tree_list); result = 0
while left <= right:
    mid = (left + right) // 2

    total = 0
    for i, num in tree_list.items():
        if i - mid > 0:
            total += (i - mid) * num
    
    if total >= need:
        left = mid + 1
        result = mid
    else:
        right = mid - 1

print(result)