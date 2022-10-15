import sys

sub = int(sys.stdin.readline())
score = list(map(int, sys.stdin.readline().split(' ')))
score.sort()

new_score = []
for i in range(len(score)):
    temp = (score[i] / max(score)) * 100
    new_score.append(temp)

avr = sum(new_score) / len(new_score)
print(avr)