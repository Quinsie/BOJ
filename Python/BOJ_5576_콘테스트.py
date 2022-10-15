import sys

w = []; k = []
for i in range(10):
    temp = int(sys.stdin.readline())
    w.append(temp)
for j in range(10):
    temp = int(sys.stdin.readline())
    k.append(temp)

w.sort(); k.sort()
print('%d %d' %((w[7] + w[8] + w[9]), (k[7] + k[8] + k[9])))