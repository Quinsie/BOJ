import sys

num = int(sys.stdin.readline())
total = 0
for i in range(num):
    temp = sys.stdin.readline().rstrip()
    pow = int(temp[:len(temp) - 1]) ** int(temp[len(temp) - 1])
    total += pow

print(total)