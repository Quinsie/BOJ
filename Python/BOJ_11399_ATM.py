import sys

num = int(sys.stdin.readline())
people = list(map(int, sys.stdin.readline().split()))
people.sort()

time = 0; count = 0
for i in people:
    time += (i + count)
    count += i

print(time)