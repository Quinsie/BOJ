import sys

num = int(sys.stdin.readline())
num_list = [0] + list(map(int, sys.stdin.readline().split()))

memo = [0]

for i in range(1, num + 1):
    if num_list[i] > memo[len(memo) - 1]:
        memo.append(num_list[i])
    else:
        left = 0
        right = len(memo)

        while left < right:
            mid = (left + right) // 2
            if memo[mid] < num_list[i]:
                left = mid + 1
            else:
                right = mid
        
        memo[right] = num_list[i]

print(len(memo) - 1)