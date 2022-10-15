import sys

a, b = sys.stdin.readline().rstrip().split(' ')
rev_a = a[2] + a[1] + a[0]
rev_b = b[2] + b[1] + b[0]
print(max(rev_a, rev_b))