import sys

num = int(sys.stdin.readline())

count = 0; count_3 = 0
while num % 5 != 0 and count_3 < 10:
    num -= 3
    count += 1
    count_3 += 1

    if num % 5 == 0:
        count_3 = 0
        break

    if num < 0:
        break

if count_3 > 0:
    print(-1)
else:
    count += num // 5
    print(count)