# BOJ 2935 : 소음

import sys

# input
num1 = int(sys.stdin.readline())
operator = sys.stdin.readline().rstrip()
num2 = int(sys.stdin.readline())

# progress
if operator == '+':
    print(num1 + num2)  # output
else:
    print(num1 * num2)  # output