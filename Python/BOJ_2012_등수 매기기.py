import sys

student = int(sys.stdin.readline())
score = []
for i in range(student):
    score.append(int(sys.stdin.readline()))
score.sort()

ans = 0
for j in range(1, student + 1):
    ans += abs(j - score[j - 1])

print(ans)