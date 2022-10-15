# BOJ 8959 : OX퀴즈

import sys

# input
num = int(sys.stdin.readline())
judge = []
for i in range(num):
    temp = sys.stdin.readline().rstrip()
    judge.append(temp)

# progress
for j in range(len(judge)):
    score = 0
    temp2 = 0
    temp_score = 0
    for k in range(len(judge[j])):
        if judge[j][k] == 'X':
            for l in range(1, temp2 + 1):
                temp_score += l
            score += temp_score
            temp_score = 0
            temp2 = 0
        elif judge[j][k] == 'O':
            temp2 += 1
        
        if k == len(judge[j]) - 1:
            for l in range(1, temp2 + 1):
                temp_score += l
            score += temp_score
            print(score)    # output