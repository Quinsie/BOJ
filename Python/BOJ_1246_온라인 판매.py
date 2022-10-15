import sys

egg, customer = map(int, sys.stdin.readline().split())
price = []
for i in range(customer):
    price.append(int(sys.stdin.readline()))

price.sort()
now = 0
maximum = 0
maximum_price = 0
people = customer

for j in price:
    if j > now:
        now = j
        if egg >= people:
            if j * people > maximum:
                maximum = j * people
                maximum_price = j
        else:
            if j * egg > maximum:
                maximum = j * egg
                maximum_price = j
    people -= 1

print('%d %d' %(maximum_price, maximum))