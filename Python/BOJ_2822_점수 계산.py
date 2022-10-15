import sys

scoreboard = []
for i in range(8):
    temp = int(sys.stdin.readline())
    scoreboard.append([temp, i + 1])

scoreboard.sort()

for j in range(3):
    del scoreboard[0]

total = 0
order = []
for k in range(5):
    total += scoreboard[k][0]
    order.append(scoreboard[k][1])

order.sort()

print(total)
for l in order:
    print(l, end = ' ')