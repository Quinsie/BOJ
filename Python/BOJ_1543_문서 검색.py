import sys

string = sys.stdin.readline().rstrip()
word = sys.stdin.readline().rstrip()
temp = ''
count = 0

for i in string:
    temp += i
    if word in temp:
        temp = ''
        count += 1

print(count)