import sys

num = list(map(int, sys.stdin.readline().rstrip()))

count = 0
while True:
    if len(num) == 1:
        result = num[0]
        break

    count += 1
    result = 0
    for i in num:
        result += i
    
    if result < 10:
        break
    else:
        num = list(map(int, str(result)))
    
if result % 3 == 0:
    print(count)
    print('YES')

else:
    print(count)
    print('NO')

# 함수로 풀어보고 싶었으니 나중에 복습하자 (21.11.04)