n = int(input()) # 모양 변수 받기
k = 0 # 보조변수 초기값

while (2 * k) < ((4 * n) - 4): # 중간 윗부분까지 그리기
    for i in range(k // 2): # 왼쪽 끝부분 모양 그리기
        print('* ', end = '')
    if (k % 2) != 0:
        print('*', end = '')
    
    if (k % 2) == 0: # 정 가운데 한무늬 반복패턴 그리기
        print('*' * ((4 * n) - (3 + (2 * k))), end = '')
    elif (k % 2) != 0:
        print(' ' * ((4 * n) - (3 + (2 * k))), end = '')
    
    if (k % 2) != 0: # 오른쪽 끝부분 모양 그리기
        print('*', end = '')    
    for i in range(k // 2):
        print(' *', end = '')
    
    print('') # 한줄 띄우고
    k += 1 # 보조변수 증가

for i in range(((n * 4) - 3) // 2): # 정중앙 그리기
    print('* ', end = '')
if ((n * 4) - 3) % 2 != 0:
    print('*')

k -= 1

while k >= 0: # 끝까지 그리기
    for i in range(k // 2): # 왼쪽 끝부분 모양 그리기
        print('* ', end = '')
    if (k % 2) != 0:
        print('*', end = '')
    
    if (k % 2) == 0: # 정 가운데 한무늬 반복패턴 그리기
        print('*' * ((4 * n) - (3 + (2 * k))), end = '')
    elif (k % 2) != 0:
        print(' ' * ((4 * n) - (3 + (2 * k))), end = '')
    
    if (k % 2) != 0: # 오른쪽 끝부분 모양 그리기
        print('*', end = '')    
    for i in range(k // 2):
        print(' *', end = '')
    
    if k != 0: # 마지막줄 공백으로 에러 생기는 것 방지용 조건
        print('') # 한줄 띄우고
    k -= 1 # 보조변수 감소