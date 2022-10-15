import sys

def gcd(x, y):
    a = max(x, y); b = min(x, y)
    while b != 0:
        temp = a
        a = b
        b = temp % a
    return a

def lcm(x, y):
    return (x * y) // gcd(x, y)

def gcd_arr(arr):
    gcd_now = arr[0]
    for i in range(1, len(arr)):
        gcd_now = gcd(gcd_now, arr[i])
    return gcd_now

def lcm_arr(arr):
    lcm_now = arr[0]
    for i in range(1, len(arr)):
        lcm_now = lcm(lcm_now, arr[i])
    return lcm_now

num = int(sys.stdin.readline())

fraction = []
numerator_arr = []
denominator_arr = []
for i in range(num):
    a, b = map(int, sys.stdin.readline().split())
    fraction.append([a, b])
    denominator_arr.append(b)

denominator = lcm_arr(denominator_arr)
for j in range(len(fraction)):
    numerator_arr.append(fraction[j][0] * (denominator // fraction[j][1]))

numerator = gcd_arr(numerator_arr)

divisor = gcd(denominator, numerator)
denominator = denominator // divisor
numerator = numerator // divisor

print('%d %d' %(numerator, denominator))