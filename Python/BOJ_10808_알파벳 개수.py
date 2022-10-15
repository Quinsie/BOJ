import sys

word = sys.stdin.readline().rstrip()

table = []
for i in range(97, 123):
    count = 0
    for j in word:
        if ord(j) == i:
            count += 1
    table.append(count)

for k in table:
    print(k, end = ' ')