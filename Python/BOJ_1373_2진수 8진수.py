import sys

b = sys.stdin.readline().rstrip()
ans = oct(int(b, 2))
print(ans[2:])