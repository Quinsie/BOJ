import sys

player = int(sys.stdin.readline())
table = []
for i in range(player):
    temp = list(map(int, sys.stdin.readline().split()))
    table.append(temp)

score = [0 for _ in range(player)]
game_1 = []; game_2 = []; game_3 = []

for j in range(player):
    game_1.append(table[j][0])
    game_2.append(table[j][1])
    game_3.append(table[j][2])

for k in range(player):
    if game_1.count(game_1[k]) == 1:
        score[k] += game_1[k]
    if game_2.count(game_2[k]) == 1:
        score[k] += game_2[k]
    if game_3.count(game_3[k]) == 1:
        score[k] += game_3[k]

for l in range(player):
    print(score[l])