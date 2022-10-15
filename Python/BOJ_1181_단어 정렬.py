import sys

num = int(sys.stdin.readline())
word = []
for i in range(num):
    temp = sys.stdin.readline().rstrip()
    word.append([temp, len(temp)])

word.sort(key = lambda x : (x[1], x[0]))

length = len(word); count = 1
while count < length:
    if word[count] == word[count - 1]:
        del word[count]
        length = len(word)
        continue
    count += 1

for k in range(len(word)):
    print(word[k][0])