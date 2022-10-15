import sys

tree = int(sys.stdin.readline())
time = list(map(int, sys.stdin.readline().split()))

time.sort(reverse = True)
for i in range(1, len(time) + 1):
    time[i - 1] += i + 1

print(max(time))