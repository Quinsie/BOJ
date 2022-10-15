# BOJ 1292 : 쉽게 푸는 문제

import sys

# input
start, end = map(int, sys.stdin.readline().split(' '))

# progress
numbers = []    # 재귀로 숫자 리스트 만들어주기
num = 1
while True:
    for i in range(num):
        numbers.append(num)
    num += 1
    if len(numbers) > 1000:
        break

# output
print(sum(numbers[(start - 1):end]))