import sys

line = int(sys.stdin.readline())
line_list = [0] + list(map(int, sys.stdin.readline().split()))

LIS = [0]
for i in range(1, line + 1):
    if line_list[i] > LIS[-1]:
        LIS.append(line_list[i])
    else:
        left = 0
        right = len(LIS)
        while left < right:
            mid = (left + right) // 2
            if LIS[mid] < line_list[i]:
                left = mid + 1
            else:
                right = mid
        LIS[right] = line_list[i]

print(len(LIS) - 1)