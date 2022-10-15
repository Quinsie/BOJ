import sys

case = int(sys.stdin.readline())
for i in range(case):
    candy, box = map(int, sys.stdin.readline().split())
    box_list = []
    for j in range(box):
        a, b = map(int, sys.stdin.readline().split())
        box_list.append(a * b)
    box_list.sort(reverse = True)
    
    now = 0; count = 0
    while now < candy:
        now += box_list[count]
        count += 1
    print(count)