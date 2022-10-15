import sys

def find(x, y, length):
    global count
    next_length = length // 2

    if length == 2:
        if x == 1 and y == 2:
            count += 1
        elif x == 2 and y == 1:
            count += 2
        elif x == 2 and y == 2:
            count += 3
        return
    
    if x <= next_length and y <= next_length:
        find(x, y, next_length)
    elif x <= next_length and y > next_length:
        count += (next_length) ** 2
        find(x, y - next_length, next_length)
    elif x > next_length and y <= next_length:
        count += ((next_length) ** 2) * 2
        find (x - next_length, y, next_length)
    else:
        count += ((next_length) ** 2) * 3
        find (x - next_length, y - next_length, next_length)

n, r, c = map(int, sys.stdin.readline().split())
count = 0
find(r + 1, c + 1, 2 ** n)
print(count)