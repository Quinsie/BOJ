import sys

case = int(sys.stdin.readline())
for c in range(case):
    num = int(sys.stdin.readline())
    signal = []
    for i in range(num):
        temp = int(sys.stdin.readline())
        signal.append((temp, i + 1))
    signal.sort()
    
    LIS = [0]
    for i in range(num):
        if signal[i][1] > LIS[-1]:
            LIS.append(signal[i][1])
        else:
            left = 0
            right = len(LIS)

            while left < right:
                mid = (left + right) // 2
                if LIS[mid] < signal[i][1]:
                    left = mid + 1
                else:
                    right = mid
            
            LIS[right] = signal[i][1]
    
    print(len(LIS) - 1)