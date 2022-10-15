import sys

word = sys.stdin.readline().rstrip().upper()

array = []
for i in range(26):
    array.append(0)

for j in word:
    array[ord(j) - 65] += 1

max_count = max(array)
if array.count(max_count) > 1:
    print('?')
else:
    print(chr(array.index(max_count) + 65))