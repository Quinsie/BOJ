import sys

def gcd(x, y):
    a = max(x, y); b = min(x, y)
    while b != 0:
        temp = a
        a = b
        b = temp % a
    return a

num = int(sys.stdin.readline())
num_arr = list(map(int, sys.stdin.readline().split()))
target = int(sys.stdin.readline())

coprime = []
for i in num_arr:
    if gcd(i, target) == 1:
        coprime.append(i)

print(sum(coprime) / len(coprime))