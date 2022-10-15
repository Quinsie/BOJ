import sys

money = int(sys.stdin.readline())

coin = 0
while money % 5 != 0:
    if money < 0:
        print(-1)
        break
    money -= 2
    coin += 1

if money % 5 == 0:
    coin += (money // 5)
    print(coin)