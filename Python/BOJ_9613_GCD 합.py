import sys

def gcd(x, y):
    a = max(x, y); b = min(x, y)
    while b != 0:
        temp = a
        a = b
        b = temp % a
    return a

case = int(sys.stdin.readline())
for i in range(case):
    table = list(map(int, sys.stdin.readline().split()))
    table = table[1:]

    gcd_total = 0
    for j in range(len(table)):
        for k in range(j + 1, len(table)):
            gcd_total += gcd(table[j], table[k])
    print(gcd_total)