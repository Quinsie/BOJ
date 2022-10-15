input_num = int(input()) # 인풋받을 숫자
first_num = 666 # 처음 숫자
while input_num != 0: # 인풋받은 숫자가 0이 아니면 계속 반복
    if '666' in str(first_num): # 만약 666이란 문자열이 first_num 안에 있으면
        input_num -= 1 # 인풋받은 숫자를 1 감소시킨다
        if input_num == 0: # 인풋받은 숫자가 0이 되면 탈출
            break
    first_num += + 1 # 인풋받은 숫자가 0이 아니면 처음 숫자 값을 1 증가시키고 재반복
print(first_num)