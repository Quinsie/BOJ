import sys

s = sys.stdin.readline().rstrip()
t = sys.stdin.readline().rstrip()

result_s = ''; result_t = ''
for i in range(len(t)):
    result_s += s
for j in range(len(s)):
    result_t += t

if result_s == result_t:
    print(1)
else:
    print(0)