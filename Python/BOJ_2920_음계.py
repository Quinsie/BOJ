import sys

numbers = list(map(int, sys.stdin.readline().split()))
s_num = sorted(numbers)
r_num = sorted(numbers, reverse = True)

if numbers == s_num:
    print('ascending')
elif numbers == r_num:
    print('descending')
else:
    print('mixed')