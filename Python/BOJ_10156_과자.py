import sys

a, b, c = map(int, sys.stdin.readline().split())
result = a * b - c
if result < 0:
    result = 0
   
print(result)