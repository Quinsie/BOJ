import sys

n = int(sys.stdin.readline())
count = 1

while n > 0:
    n -= count
    count += 1

if count % 2 == 0:
    print('%d/%d' %(1 - n, count + n - 1))
else:
    print('%d/%d' %(count + n - 1, 1 - n))