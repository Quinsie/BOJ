# input
n, space = map(int, input().split(' '))
num = []
for i in range(n):
    num.append(i + 1)

# progress
count = 0   # 위치 표기를 위한 보조숫자
result = [] # 결과 표기를 위한 보조리스트
while bool(num) == True:    # num 리스트에 숫자가 남지 않을 때까지 반복
    count += space
    if count > len(num):    # 보조숫자가 남아있는 리스트 총길이보다 길다면
        while count > len(num): # 보조숫자가 리스트 총길이보다 작거나 같아질 때까지 연산
            count -= len(num)
    result.append(num[count - 1])
    del num[count - 1]  # 결과리스트에 추가한 요소를 빼고 카운트에서 1을 제함
    count -= 1

# output
print('<', end = '')
for j in range(n - 1):
    print(result[j], end = ', ')
print(result[n - 1], end = '>')