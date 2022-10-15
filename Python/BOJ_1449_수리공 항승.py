import sys

broken, tape = map(int, sys.stdin.readline().split())
pipe = list(map(int, sys.stdin.readline().split()))
pipe.sort()

loc = 0; count = 0
while loc < broken:
    temp = loc
    while pipe[temp] < pipe[loc] + tape:
        temp += 1
        if temp >= broken:
            break
    loc = temp
    count += 1

print(count)