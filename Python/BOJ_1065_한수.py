import sys

num = sys.stdin.readline().rstrip()

count = 0
while int(num) != 0:
    if len(num) < 3:
        count += 1

    elif len(num) == 3:
        if int(num[2]) - int(num[1]) == int(num[1]) - int(num[0]):
            count += 1
        
    num = str(int(num) - 1)
    

print(count)