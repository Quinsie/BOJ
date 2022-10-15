N = int(input())
files = list(map(int, input().split()))
files.sort()
result = 0

for i in range(N):
    left = i
    right = N-1
    while left <= right:
        mid = (left + right) // 2
        if files[i] >= files[mid] * 0.9:
            left = mid + 1
        else: right = mid - 1
    result += left - i - 1
    
print(result)