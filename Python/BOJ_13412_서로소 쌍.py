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
    target = int(sys.stdin.readline())
    count = 0
    for num_1 in range(1, int(target ** (1 / 2)) + 1):
        if target % num_1 != 0:
            continue
        else:
            num_2 = target // num_1
            if gcd(num_1, num_2) == 1:
                count += 1
    
    print(count)