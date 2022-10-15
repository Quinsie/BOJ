import sys
import collections

def bfs():
    queue = collections.deque()
    queue.append([a, ""])

    while queue:
        number, result = queue.popleft()

        dn = (number * 2) % 10000
        if dn == b:
            return result + "D"
        elif arr[dn] == 0:
            arr[dn] = 1
            queue.append([dn, result + "D"])

        sn = number - 1 if number != 0 else 9999
        if sn == b:
            return result + "S"
        elif arr[sn] == 0:
            arr[sn] = 1
            queue.append([sn, result + "S"])

        ln = int(number % 1000 * 10 + number / 1000)
        if ln == b:
            return result + "L"
        elif arr[ln] == 0:
            arr[ln] = 1
            queue.append([ln, result + "L"])

        rn = int(number % 10 * 1000 + number // 10)
        if rn == b:
            return result + "R"
        elif arr[rn] == 0:
            arr[rn] = 1
            queue.append([rn, result + "R"])

case = int(sys.stdin.readline())
for i in range(case):
    a, b = map(int, sys.stdin.readline().split())
    arr = [0 for i in range(10000)]
    print(bfs())