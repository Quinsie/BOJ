import sys

x, y, w, h = map(int, sys.stdin.readline().split())

x_min = min(x, w - x)
y_min = min(y, h - y)
print(min(x_min, y_min))