import sys

column, row, block = map(int, sys.stdin.readline().split())
table = [0 for _ in range(257)]

for i in range(column):
    temp = list(map(int, sys.stdin.readline().split()))
    for j in temp:
        table[j] += 1

for i in range(257):
    if table[i] != 0:
        minimum = i
        break

for i in range(256, -1, -1):
    if table[i] != 0:
        maximum = i
        break

target_time = 10e9; target_height = 0
for height in range(maximum, minimum - 1, -1):
    need_block = 0
    get_block = 0

    for i in range(minimum, maximum + 1):
        get_block += (i - height) * table[i] if (i - height) * table[i] >= 0 else 0
        need_block += (height - i) * table[i] if (height - i) * table[i] >= 0 else 0

    if need_block <= get_block + block:
        time = need_block + (get_block * 2)
        if time < target_time:
            target_time = time
            target_height = height

print(target_time, target_height)