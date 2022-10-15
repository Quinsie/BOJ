import sys

word = sys.stdin.readline().rstrip()

count = 0
for i in word:
    print(i, end = '')
    count += 1
    if count == 10:
        print()
        count = 0