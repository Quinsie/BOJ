import sys

n = int(sys.stdin.readline())
s = list(map(int, sys.stdin.readline().split()))
s_list = []
s_list.append(s[0])
for i in range(1, n):
    s_list.append((s[i] * (i + 1)) - sum(s_list))
for i in s_list:
    print(i, end=' ')