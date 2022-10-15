import sys

def gcd(x, y):
    big = max(x, y); small = min(x, y)
    remainder = big % small

    if small == 0:
        return big
    
    if remainder == 0:
        return small
    else:
        return gcd(small, remainder)

num = int(sys.stdin.readline())
for i in range(num):
    num_list = list(map(int, sys.stdin.readline().split()))
    pair_gcd = []
    for j in range(1, len(num_list)):
        for k in range(j):
            temp = gcd(num_list[k], num_list[j])
            if temp in pair_gcd:
                continue
            else:
                pair_gcd.append(temp)
    
    print(max(pair_gcd))