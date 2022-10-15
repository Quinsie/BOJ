import sys

total = int(sys.stdin.readline())
temp_total = 0
for i in range(9):
    temp_price = int(sys.stdin.readline())
    temp_total += temp_price
print(total - temp_total)