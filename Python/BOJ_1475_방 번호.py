import sys

num = sys.stdin.readline().rstrip()
num_list = [0 for _ in range(10)]

for i in num:
    num_list[int(i)] += 1

num_list[6] += num_list[9]
del num_list[9]

if num_list[6] % 2 != 0:
    num_list[6] = (num_list[6] // 2) + 1
else:
    num_list[6] = (num_list[6] // 2)

print(max(num_list))