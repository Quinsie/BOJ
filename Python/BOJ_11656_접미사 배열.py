import sys

s = sys.stdin.readline().rstrip()

l = []
length = len(s)
for i in range(length):
    l.append(s[i:])
l.sort()
for i in l:
    print(i)