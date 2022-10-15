import sys

word = sys.stdin.readline().rstrip().upper()

array = []
for i in range(26):
    array.append(-1)

count = 0
for j in word:
    if array[ord(j) - 65] == -1:
        array[ord(j) - 65] = count
    count += 1

for k in array:
    print(k, end = ' ')