import sys

num = int(sys.stdin.readline())

i = 2
counter = 1
while i * i <= num:
    if num % i == 0:
        counter = num // i
        break
    i += 1

print(num - counter)