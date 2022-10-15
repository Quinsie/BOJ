import sys

num = int(sys.stdin.readline())
s = []

for i in range(int(num)):
    temp = sys.stdin.readline().rstrip().split()

    if temp[0] == 'add':
        if int(temp[1]) in s:
            continue
        else:
            s.append(int(temp[1]))
    
    elif temp[0] == 'remove':
        if int(temp[1]) in s:
            s.remove(int(temp[1]))
        else:
            continue
    
    elif temp[0] == 'check':
        if int(temp[1]) in s:
            print(1)
        else:
            print(0)
    
    elif temp[0] == 'toggle':
        if int(temp[1]) in s:
            s.remove(int(temp[1]))
        else:
            s.append(int(temp[1]))
    
    elif temp[0] == 'all':
        s = [i for i in range(1, 21)]
    
    else:
        s = []