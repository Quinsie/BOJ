import sys

book = int(sys.stdin.readline())
book_list = [0] + list(map(int, sys.stdin.readline().split()))
LIS = [0]

for i in range(1, book + 1):
    if book_list[i] > LIS[-1]:
        LIS.append(book_list[i])
    else:
        left = 0
        right = len(LIS)
        while left < right:
            mid = (left + right) // 2
            if LIS[mid] < book_list[i]:
                left = mid + 1
            else:
                right = mid
        LIS[right] = book_list[i]

print(book - len(LIS) + 1)