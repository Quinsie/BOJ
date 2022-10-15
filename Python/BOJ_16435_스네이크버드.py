import sys

fruits, snakebird = map(int, sys.stdin.readline().split())
fruits_list = list(map(int, sys.stdin.readline().split()))

fruits_list.sort()
for i in fruits_list:
    if i <= snakebird:
        snakebird += 1

print(snakebird)