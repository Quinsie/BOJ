import sys

def binary_search(left, right, target, arr):
    mid = (left + right) // 2
    if arr[mid] == target:
        print(1)
        return
    if left == right and arr[mid] != target:
        print(0)
        return
    if target < arr[left] or target > arr[right]:
        print(0)
        return
    
    if arr[mid] < target:
        binary_search(mid + 1, right, target, arr)
    elif arr[mid] > target:
        binary_search(left, mid - 1, target, arr)

n = int(sys.stdin.readline())
n_list = sorted(list(map(int, sys.stdin.readline().split())))
m = int(sys.stdin.readline())
m_list = list(map(int, sys.stdin.readline().split()))

for i in range(m):
    num = m_list[i]
    binary_search(0, n - 1, num, n_list)