import sys

num = int(sys.stdin.readline())
table = list(map(int, sys.stdin.readline().split()))

decimal = 0
for i in table:
    count = 0

    if i == 1:
        continue
    
    for j in range(2, int((i ** (1 / 2)) + 1)):
        if i % j == 0:
            count += 1
            break

    if count == 0:
        decimal += 1
    else:
        continue

print(decimal)