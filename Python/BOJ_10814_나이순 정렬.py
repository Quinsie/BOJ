import sys

num = int(sys.stdin.readline())
member = []
for i in range(num):
    age, name = sys.stdin.readline().rstrip().split()
    member.append([int(age), name, i + 1])

member.sort(key = lambda x : (x[0], x[2]))

for j in range(num):
    print('%d %s' %(member[j][0], member[j][1]))