# BOJ 13305 : 주유소

import sys

# input
city = int(sys.stdin.readline())
space = list(map(int, sys.stdin.readline().split(' ')))
fuel = list(map(int, sys.stdin.readline().split(' ')))

# progress
distance = 0    # 누적 거리 변수 초기화
now_fuel = 0    # 현재 기름값 변수 선언
price = 0   # 누적 가격 변수 선언

low_fuel = fuel[0]  # 최초 기름 최저가 설정

for i in range(1, len(fuel)):   # 2번째 주유소부터 판별 시작
    now_fuel = fuel[i]
    distance += space[i - 1]
    if now_fuel >= low_fuel:
        if i == len(fuel) - 1:
            price += distance * low_fuel
        continue
    else:
        price += distance * low_fuel
        distance = 0
        low_fuel = now_fuel

# output
print(price)