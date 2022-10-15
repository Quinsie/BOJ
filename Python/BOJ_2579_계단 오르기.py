import sys

stairs = int(sys.stdin.readline())
stairs_list = [0]
for i in range(stairs):
    stairs_list.append(int(sys.stdin.readline()))

cache = [0 for _ in range(301)]
cache[0] = stairs_list[0]
cache[1] = stairs_list[1]
if stairs > 1:
    cache[2] = stairs_list[1] + stairs_list[2]
if stairs > 2:
    for j in range(3, stairs + 1):
        cache[j] = max(stairs_list[j] + cache[j - 2], stairs_list[j] + stairs_list[j - 1] + cache[j - 3])

print(cache[stairs])