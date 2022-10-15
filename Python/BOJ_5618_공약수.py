import sys

def gcd(x, y):
    big = max(x, y); small = min(x, y)
    remainder = big % small

    if small == 0:
        return big
    
    if remainder == 0:
        return small
    else:
        return gcd(small, remainder)

def gcd_3(x, y, z):
    return gcd(gcd(x, y), z)

def aliquot(n):
    aliquot = []
    aliquot_reverse = []

    for i in range(1, int(n ** (1 / 2)) + 1):
        if n % i == 0:
            aliquot.append(i)
            if i != (n // i):
                aliquot_reverse.append(n // i)
        
    return aliquot + aliquot_reverse[::-1]

num = int(sys.stdin.readline())
if num == 2:
    a, b = map(int, sys.stdin.readline().split())
    temp_list = aliquot(gcd(a, b))
    for i in temp_list:
        print(i)

else:
    a, b, c = map(int, sys.stdin.readline().split())
    temp_list = aliquot(gcd(gcd(a, b), c))
    for i in temp_list:
        print(i)