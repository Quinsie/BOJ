import sys

info = []
for i in range(5):
    temp = int(sys.stdin.readline())
    info.append(temp)

x_inc = info[0] * info[4]

overpay = (info[4] - info[2]) * info[3]
if overpay < 0:
    overpay = 0
y_inc = info[1] + overpay

print(min(x_inc, y_inc))