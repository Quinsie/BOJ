import sys

while True:
    num = sys.stdin.readline().rstrip()
    if num == '0':
        break

    r_num = ''
    for i in num:
        r_num = i + r_num
    
    if num == r_num:
        print('yes')
    else:
        print('no')