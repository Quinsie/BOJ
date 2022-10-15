import sys

score = []
for i in range(5):
    temp = int(sys.stdin.readline())
    score.append(temp)

total = 0
for j in score:
    if j < 40:
        total += 40
        continue
    total += j

avr = int(total / 5)
print(avr)