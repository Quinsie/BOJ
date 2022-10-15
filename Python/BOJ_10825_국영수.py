import sys

num = int(sys.stdin.readline())
table = []
for i in range(num):
    temp = sys.stdin.readline().rstrip().split()
    temp_name = temp[0]
    temp = list(map(int, temp[1:]))
    temp.insert(0, temp_name)
    table.append(temp)
  
table.sort(key = lambda x: (-x[1], x[2], -x[3], x[0]))

for j in range(num):
    print(table[j][0])