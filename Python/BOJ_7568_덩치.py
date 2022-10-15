# BOJ 7568번 : 덩치

case = int(input()) # 등수 매길 테스트 케이스 숫자 입력
info = []
for i in range(case):
    temp = list(map(int, input().split(' ')))
    temp.append(1)
    info.append(temp)

for j in range(case):
    for k in range(case):
        if info[j][0] < info[k][0] and info[j][1] < info[k][1]:
            info[j][2] += 1

for l in range(case):
    print(info[l][2], end = ' ')