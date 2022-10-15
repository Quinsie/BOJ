import sys

def gcd(x, y):
    a = max(x, y); b = min(x, y)
    while b != 0:
        temp = a
        a = b
        b = temp % a
    return a

def aliquot(n):
    aliquot = []
    aliquot_reverse = []

    for i in range(1, int(n ** (0.5)) + 1):
        if n % i == 0:
            aliquot.append(i)
            if i != (n // i):
                aliquot_reverse.append(n // i)
    
    return aliquot + aliquot_reverse[::-1]

red, green = map(int, sys.stdin.readline().split())
gcd_rd = gcd(red, green)
aliquot_list = aliquot(gcd_rd)

for i in range(len(aliquot_list)):
    print('%d %d %d' %(aliquot_list[i], red // aliquot_list[i], green // aliquot_list[i]))