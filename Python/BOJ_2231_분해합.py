import sys

num = int(sys.stdin.readline())

target = 1; count = 0
while target < num:
    s_target = str(target)
    temp = []
    for i in s_target:
        temp.append(int(i))
    
    if target + sum(temp) == num:
        count += 1
        print(target)
        break
    
    target += 1

if count == 0:
    print(0)