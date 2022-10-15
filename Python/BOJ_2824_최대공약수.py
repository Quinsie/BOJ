import sys

# input
num_1 = int(sys.stdin.readline())
num_1_list = list(map(int, sys.stdin.readline().split()))
num_2 = int(sys.stdin.readline())
num_2_list = list(map(int, sys.stdin.readline().split()))

# progress
total_1 = 1; total_2 = 1
for i in num_1_list:
    total_1 *= i

for i in num_2_list:
    total_2 *= i

sys.setrecursionlimit(10**5)    # 최대 재귀한도 설정
def gcd(x, y):
    big = max(x, y); small = min(x, y)
    remainder = big % small

    if small == 0:
        return big
    
    if remainder == 0:
        return small
    else:
        return gcd(small, remainder)

# output
result = str(gcd(total_1, total_2))
if len(result) > 9:
    print(result[len(result) - 9:])
else:
    print(result)