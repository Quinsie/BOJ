import sys

def gcd(x, y):
    a = max(x, y); b = min(x, y)
    while b != 0:
        temp = a
        a = b
        b = temp % a
    return a

num = int(sys.stdin.readline())
num_list = list(map(int, sys.stdin.readline().split()))

first = num_list[0]
num_list = num_list[1:]

for i in num_list:
    divisor = gcd(first, i)
    numerator = first // divisor
    denominator = i // divisor
    print('%d/%d' %(numerator, denominator))