import sys

arr = list(map(int, sys.stdin.readline().split()))

while True:
    if arr == [1, 2, 3, 4, 5]:
        break

    else:
        for i in range(4):
            if arr[i] > arr[i + 1]:
                temp = arr[i]
                arr[i] = arr[i + 1]
                arr[i + 1] = temp
            
                for j in arr:
                    print(j, end = ' ')
                print()