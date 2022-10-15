num = int(input())
answer = []
for i in range(num):
    floor = int(input())
    room = int(input())

    apt = [[]]
    for j in range(1, room + 1):
        apt[0].append(j)

    for k in range(floor):
        apt.append([1])

    for l in range(1, floor + 1):
        for m in range(room - 1):
            apt[l].append(apt[l][m] + apt[l - 1][m + 1])
    
    answer.append(apt[floor][room - 1])

for n in answer:
    print(n)