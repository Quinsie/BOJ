import sys

case = []
for i in range(9):
    temp = int(sys.stdin.readline())
    case.append(temp)

print(max(case))
print(case.index(max(case)) + 1)