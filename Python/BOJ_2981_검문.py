import sys
import collections

def gcd(x, y):
    a = max(x, y); b = min(x, y)
    while b != 0:
        temp = a
        a = b
        b = temp % b
    return a

def gcd_arr(arr):
    gcd_now = arr[0]
    for i in range(1, len(arr)):
        gcd_now = gcd(gcd_now, arr[i])
    return gcd_now

num = int(sys.stdin.readline())
first_num = int(sys.stdin.readline())
gap = []
for i in range(1, num):
    temp = int(sys.stdin.readline())
    gap.append(abs(temp - first_num))

gcd_num = gcd_arr(gap)
ans = []
for i in range(1, int(gcd_num ** 0.5) + 1):
    if i == gcd_num ** 0.5:
        ans.append(i)
        break
    if gcd_num % i == 0:
        ans.append(i)
        ans.append(gcd_num // i)
ans.sort()
del ans[0]
for i in ans:
    print(i, end = ' ')