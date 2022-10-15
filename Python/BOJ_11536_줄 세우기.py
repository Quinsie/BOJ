import sys

num = int(sys.stdin.readline())
name = []
for i in range(num):
    name.append(sys.stdin.readline().rstrip())

if name == sorted(name):
    print('INCREASING')
elif name == sorted(name, reverse = True):
    print('DECREASING')
else:
    print('NEITHER')