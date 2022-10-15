import sys

num = int(sys.stdin.readline())
num_list = [0] + list(map(int, sys.stdin.readline().split()))
lis_len = [1 for _ in range(num)]

memo = [-10e9]

for i in range(1, num + 1):
    if num_list[i] > memo[len(memo) - 1]:
        memo.append(num_list[i])
        lis_len[i - 1] = len(memo) - 1
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
        lis_len[i - 1] = right

ans = []
now = len(memo) - 1
for i in range(num - 1, -1, -1):
    if lis_len[i] == now:
        ans.append(num_list[i + 1])
        now -= 1

        if now == 0:
            break


print(len(memo) - 1)
for i in range(len(memo) - 2, -1, -1):
    print(ans[i], end = ' ')