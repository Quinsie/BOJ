list = [] # 정렬 사용을 위한 리스트
lines = int(input()) # 줄 개수 입력
for i in range(lines): # 입력받은 줄 개수동안,
    num = int(input()) # 임시 숫자에 수치 입력받음
    list.append(num) # 이후 임시 리스트에 집어넣음

list.sort()

for l in list: # 출력
    print(l)