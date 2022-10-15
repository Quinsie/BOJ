import sys

geminis = list(map(int, sys.stdin.readline().split()))
gullivers = list(map(int, sys.stdin.readline().split()))

geminis_score = 0; gullivers_score = 0
flag = False
for i in range(9):
    geminis_score += geminis[i]
    if geminis_score > gullivers_score:
        flag = True
        break
    gullivers_score += gullivers[i]

if flag == True:
    print('Yes')
else:
    print('No')