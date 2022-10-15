import sys

burger = []
drink = []

for i in range(3):
    temp1 = int(sys.stdin.readline())
    burger.append(temp1)

for j in range(2):
    temp2 = int(sys.stdin.readline())
    drink.append(temp2)

set = int(min(burger) + min(drink)) - 50
print(set)