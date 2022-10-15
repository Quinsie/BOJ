import sys

num = int(sys.stdin.readline())
judge = input().split(' ')

score = 0
count = 0
temp_score = 0
for i in judge:
    if i == '1':
        count += 1
    elif i == '0':
        for j in range(1, count + 1):
            temp_score += j
        score += temp_score
        count = 0
        temp_score = 0

for k in range(1, count + 1):
    temp_score += k
score += temp_score
print(score)