arr = [i for i in range(1, 10001)]

for j in range(1, 10001):
    total = 0
    num = str(j)
    for k in num:
        total += int(k)
    total += j
    if total < 10001:
        arr[total - 1] = 0

for l in arr:
    if l > 0:
        print(l)