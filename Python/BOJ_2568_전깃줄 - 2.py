import sys

line = int(sys.stdin.readline())
table = []
for i in range(line):
    a, b = map(int, sys.stdin.readline().split())
    table.append((a, b))

table.sort()

num_list = [0]
for i in range(line):
    num_list.append(table[i][1])
LIS = [-10e8]
LIS_len = [1 for _ in range(line)]

for i in range(1, line + 1):
    if num_list[i] > LIS[len(LIS) - 1]:
        LIS.append(num_list[i])
        LIS_len[i - 1] = len(LIS) - 1
    else:
        left = 0
        right = len(LIS)
        while left < right:
            mid = (left + right) // 2
            if LIS[mid] < num_list[i]:
                left = mid + 1
            else:
                right = mid
        
        LIS[right] = num_list[i]
        LIS_len[i - 1] = right

ans = []
now = max(LIS_len)
for i in range(line - 1, -1, -1):
    if LIS_len[i] == now:
        now -= 1
    else:
        ans.append(table[i][0])

target = line - len(LIS) + 1
print(target)
if ans:
    for i in range(target - 1, -1, -1):
        print(ans[i])
else:
    print(0)