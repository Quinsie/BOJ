import sys

length = int(sys.stdin.readline())
stack = []; print_arr = []
now = 1; flag = False

for i in range(length):
    num = int(sys.stdin.readline())

    if flag == True:
        continue

    while now <= num:
        stack.append(now)
        print_arr.append('+')
        now += 1
    
    if stack[-1] == num:
        stack.pop()
        print_arr.append('-')
    else:
        flag = True

if flag == False:
    for j in print_arr:
        print(j)
else:
    print('NO')