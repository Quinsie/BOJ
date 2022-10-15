import sys

# input
a, b = map(int, sys.stdin.readline().split())
max = max(a, b); min = min(a, b)

# progress
gcd = 0; lcm = 0
for i in range(min, 0, -1):
    if max % i == 0 and min % i == 0:
        gcd = i
        break

num = max
while True:
    if num % max == 0 and num % min == 0:
        lcm = num
        break
    num += max

# output
print(gcd)
print(lcm)