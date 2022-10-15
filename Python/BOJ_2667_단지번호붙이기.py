import sys

def search(x, y):
    global nums
    
    if table[x][y] == '1':
        nums += 1
    visited.append((x, y))
    
    for i in range(4):
        new_x = x + dx[i]; new_y = y + dy[i]
        if 0 <= new_x < size and 0 <= new_y < size and table[new_x][new_y] == '1' and (new_x, new_y) not in visited:
            search(new_x, new_y)

size = int(sys.stdin.readline())
table = []
for i in range(size):
    table.append(sys.stdin.readline().rstrip())

visited = []
apartment = []
dx = [1, -1, 0, 0]; dy = [0, 0, 1, -1]
for j in range(size):
    for k in range(size):
        if table[j][k] == '1' and (j, k) not in visited:
            nums = 0
            search(j, k)
            apartment.append(nums)

apartment.sort()
print(len(apartment))
for l in apartment:
    print(l)