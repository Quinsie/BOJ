import sys

num = sys.stdin.readline().rstrip()
num_list = []

for i in num:
    num_list.append(int(i))

if sum(num_list) % 3 != 0 or num_list.count(0) == 0:
    print(-1)

else:
    num_list.sort(reverse = True)
    result = ''
    for j in num_list:
        result += str(j)
    print(result)