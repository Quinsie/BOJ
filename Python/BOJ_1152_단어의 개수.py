import sys

sentence = sys.stdin.readline().rstrip().split(' ')
for i in sentence:
    if len(i) == 0:
        sentence.remove(i)
print(len(sentence))