import sys

file = int(sys.stdin.readline())
pattern = sys.stdin.readline().rstrip().split('*')
start = pattern[0]; end = pattern[1]

for j in range(file):
    name = sys.stdin.readline().rstrip()
    if name[:len(start)] == start and name[len(name) - len(end):] == end and len("".join(pattern)) <= len(name):
        print('DA')
    else:
        print('NE')