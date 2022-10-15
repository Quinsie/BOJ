import sys

h, w = map(int, sys.stdin.readline().split())

table = []
for i in range(h):
    table.append(sys.stdin.readline().rstrip())

schedule = [[] for _ in range(h)]

for j in range(h):
    first_cloud = 0; time = 0
    for k in table[j]:
        if k == '.' and first_cloud == 0:
            schedule[j].append(-1)
        elif k == 'c':
            time = 0
            schedule[j].append(time)
            if first_cloud == 0:
                first_cloud = 1
        elif k == '.' and first_cloud == 1:
            time += 1
            schedule[j].append(time)

for l in range(h):
    for m in schedule[l]:
        print(m, end = ' ')
    print()