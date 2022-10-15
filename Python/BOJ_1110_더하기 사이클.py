import sys

num = sys.stdin.readline().rstrip()
first_num = int(num)

count = 0
while True:

    if len(num) == 1:
        num = '0' + num

    front = num[1]
    back = str(int(num[0]) + int(num[1]))
    if len(back) != 1:
        back = back[1]

    num = front + back
    count += 1
    
    if first_num == int(num):
        break

print(count)