import sys
import collections

def search(start, end, prime):
    queue = collections.deque()
    queue.append((start, 0))
    check = [0 for _ in range(10000)]
    check[start] = 1

    while queue:
        num, count = queue.popleft()
        if num == end:
            return count

        num = str(num)
        for i in range(4):
            for j in range(10):
                new_num = num[:i] + str(j) + num[i + 1:]
                new_num = int(new_num)
                if new_num in prime and check[new_num] == 0:
                    check[new_num] = 1
                    queue.append((new_num, count + 1))

def eratos():
    check = [0 for _ in range(10000)]
    check[0] = 1; check[1] = 1
    for i in range(10000):
        if check[i] == 0:
            for j in range(i + i, 10000, i):
                check[j] = 1

    return [i for i in range(1000, 10000) if check[i] == 0]

prime = eratos()
case = int(sys.stdin.readline())
for c in range(case):
    start, end = map(int, sys.stdin.readline().split())
    print(search(start, end, prime))