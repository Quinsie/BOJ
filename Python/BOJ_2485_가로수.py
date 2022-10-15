import sys

def gcd(x, y):
    a = max(x, y); b = min(x, y)
    while b != 0:
        temp = a
        a = b
        b = temp % a
    return a

def gcd_arr(arr):
    gcd_now = arr[0]
    for i in range(1, len(arr)):
        gcd_now = gcd(gcd_now, arr[i])
    return gcd_now

tree = int(sys.stdin.readline())
tall = []
for i in range(tree):
    tall.append(int(sys.stdin.readline()))

gap_list = []
for j in range(len(tall) - 1):
    gap_list.append(tall[j + 1] - tall[j])

gap = gcd_arr(gap_list)
count = 0
for k in gap_list:
    if (k // gap) - 1 > 0:
        count += (k // gap) - 1

print(count)