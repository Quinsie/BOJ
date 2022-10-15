import sys

num = int(sys.stdin.readline())
num_list = list(map(int, sys.stdin.readline().split()))

LIS_reverse = [1 for _ in range(num)]
            
for i in range(num - 1, -1, -1): # reverse
    for j in range(num - 1, i, -1):
        if num_list[i] > num_list[j]:
            LIS_reverse[i] = max(LIS_reverse[i], LIS_reverse[j] + 1)

print(max(LIS_reverse))