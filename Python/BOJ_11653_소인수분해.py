import sys

num = int(sys.stdin.readline())

target = 2
while num != 1:
    if num % target == 0:
        num = num // target
        print(target)
    
    else:
        target += 1