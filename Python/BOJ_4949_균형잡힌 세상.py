import sys
import collections

while True:
    string = sys.stdin.readline().rstrip()
    if string == '.':
        break

    flag = True
    table = collections.deque()
    for i in string:
        if i == '(' or i == '[':
            table.append(i)
        elif i == ')':
            if len(table) == 0:
                flag = False
                break
            temp = table.pop()
            if temp == '[':
                flag = False
                break
        elif i == ']':
            if len(table) == 0:
                flag = False
                break
            temp = table.pop()
            if temp == '(':
                flag = False
                break
    
    if flag == True and not table:
        print('yes')
    else:
        print('no')