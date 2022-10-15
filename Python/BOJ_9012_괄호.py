# BOJ 9012번 : 괄호

num = int(input())  # input받는 과정
case = []
for i in range(num):
    temp = input()
    case.append(temp)

final = []
for j in range(num):    # 판정 시작
    count = 0   # (와 )를 세기 위한 보조변수 설정
    for k in case[j]:
        if k == '(':    # (이 추가될 때마다 1을 더하고
            count += 1
        elif k == ')':  # )이 추가될 때마다 1을 뺀다. (0이 아니면 완전형이 아니기 때문)
            count -= 1
        
        if count < 0:   # 카운트가 음수가 되면 거기서 끝. )이 (보다 많이 나온 시점.
            final.append('NO')
            break

    if count > 0:  # 만약 카운트가 0보다 크면 NO (0보다 작은건 위에서 이미 검사함)
        final.append('NO')
    elif count == 0:   # 만약 카운트가 0이면 YES
        final.append('YES')

for l in final: # 출력
    print(l)