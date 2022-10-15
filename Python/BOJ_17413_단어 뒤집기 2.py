# BOJ 17413 : 단어 뒤집기 2

import sys

# input
text = sys.stdin.readline().rstrip()    # 입력된 문자열 오른쪽 필요없는건 다 버림

# progress
inside = 0   # 태그 안인지 밖인지 구분하기 위한 변수
word = ''   # 단어별로 저장을 위함
result = '' # 출력할 결과
for i in text:
    if inside == 0:  # 태그 안이 아닌 경우
        if i == '<':    # 태그가 열리면
            word += i
            inside = 1  # 태그 변수 변환
        elif i == ' ':  # 공백이 입력되면
            word += i
            result += word
            word = ''
        else:   # 문자가 입력되면
            word = i + word # 역순으로 추가해줘야 하기 때문에 새로 오는 문자를 앞으로
    
    else:   # 태그 안인 경우
        word += i
        if i == '>':    # 태그가 닫힐 경우
            result += word
            word = ''
            inside = 0  # 태그 변수 변환

# output
print(result + word)