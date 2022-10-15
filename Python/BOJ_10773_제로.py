# BOJ 10773번 : 제로

# input
n = int(input())  # 테스트 케이스 개수 인풋
case = []   # 테스트 케이스 리스트 형성
for i in range(n):    # 테스트 케이스 개수만큼 반복
    temp_a = int(input())
    case.append(temp_a)

# progress
zero = 0    # 현재까지 나온 0의 개수
count = 0   # 계산 보조변수
num = []    # 최종 연산될 숫자들
temp_b = [] # 임시 리스트

for j in range(n):
    temp_b.append(case[j])
    count += 1

    if case[j] == 0:  # 만약 j가 0이 나오면
        del temp_b[count - 1]
        count -= 1   # 계산 보조변수 1 뺌 (제자리 유지를 위함)
        zero += 1

        if j == (n - 1):
            while zero != 0:
                if len(temp_b) == 0:
                    del num[len(num) - 1]
                    zero -= 1
                    continue
                del temp_b[len(temp_b) - 1]
                zero -= 1
            for o in temp_b:
                num.append(o)
            
    
    elif case[j] != 0 and case[j - 1] == 0: # j가 0이 아니고 j이전까지 0이었다면
        del temp_b[count - 1]
        count -= 1
        while zero != 0:
            if len(temp_b) == 0:
                del num[len(num) - 1]
                zero -= 1
                continue
            del temp_b[len(temp_b) - 1]
            zero -= 1
        for k in temp_b:
            num.append(k)
        
        temp_b = []
        count = 0
        zero = 0
        temp_b.append(case[j])
        count += 1

        if j == (n - 1):
            for l in temp_b:
                num.append(l)
    
    elif j == (n - 1):  # 마지막 숫자라면
        for m in temp_b:
            num.append(m)

print(sum(num))