import sys

student, multitab = map(int, sys.stdin.readline().split(' '))
hole = list(map(int, sys.stdin.readline().split(' ')))

usable_hole = []
for i in hole:
    temp = (i // 2) + (i % 2)
    usable_hole.append(temp)

if student <= sum(usable_hole):
    print('YES')
else:
    print('NO')