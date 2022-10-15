import sys

while True:
    try:
        num = int(sys.stdin.readline())
        num_list = [0] + list(map(int, sys.stdin.readline().split()))

        LIS = [0]
        for i in range(1, num + 1):
            if num_list[i] > LIS[-1]:
                LIS.append(num_list[i])
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
        print(len(LIS) - 1)

    except:
        break