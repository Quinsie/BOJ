import sys

length = int(sys.stdin.readline())
string = sys.stdin.readline().rstrip()
ans = 0

for i in range(length):
    ans += (ord(string[i]) - 96) * (31 ** i)
print(ans % 1234567891)