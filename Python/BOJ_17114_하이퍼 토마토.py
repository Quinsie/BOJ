import sys
import collections

def bfs(table, tomato):
    dA = [1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    dB = [0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    dC = [0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    dD = [0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    dE = [0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    dF = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    dG = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0]
    dH = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0]
    dI = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0]
    dJ = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0]
    dK = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1]

    time = 0
    while tomato:
        A, B, C, D, E, F, G, H, I, J, K, count = tomato.popleft()
        if count > time:
            time = count

        for loof in range(22):
            nA = A + dA[loof]
            nB = B + dB[loof]
            nC = C + dC[loof]
            nD = D + dD[loof]
            nE = E + dE[loof]
            nF = F + dF[loof]
            nG = G + dG[loof]
            nH = H + dH[loof]
            nI = I + dI[loof]
            nJ = J + dJ[loof]
            nK = K + dK[loof]

            if 0 <= nA < len_list[10] and 0 <= nB < len_list[9] and 0 <= nC < len_list[8] and 0 <= nD < len_list[7] and 0 <= nE < len_list[6] and 0 <= nF < len_list[5] and 0 <= nG < len_list[4] and 0 <= nH < len_list[3] and 0 <= nI < len_list[2] and 0 <= nJ < len_list[1] and 0 <= nK < len_list[0]:
                if table[nA][nB][nC][nD][nE][nF][nG][nH][nI][nJ][nK] == 0:
                    table[nA][nB][nC][nD][nE][nF][nG][nH][nI][nJ][nK] = 1
                    tomato.append((nA, nB, nC, nD, nE, nF, nG, nH, nI, nJ, nK, count + 1))
    
    return time

len_list = list(map(int, sys.stdin.readline().split()))
table = [[[[[[[[[[list(map(int, sys.stdin.readline().split())) for _ in range(len_list[1])] for _ in range(len_list[2])] for _ in range(len_list[3])] for _ in range(len_list[4])] for _ in range(len_list[5])] for _ in range(len_list[6])] for _ in range(len_list[7])] for _ in range(len_list[8])] for _ in range(len_list[9])] for _ in range(len_list[10])]

tomato = collections.deque()
for a in range(len_list[10]):
    for b in range(len_list[9]):
        for c in range(len_list[8]):
            for d in range(len_list[7]):
                for e in range(len_list[6]):
                    for f in range(len_list[5]):
                        for g in range(len_list[4]):
                            for h in range(len_list[3]):
                                for i in range(len_list[2]):
                                    for j in range(len_list[1]):
                                        for k in range(len_list[0]):
                                            if table[a][b][c][d][e][f][g][h][i][j][k] == 1:
                                                tomato.append((a, b, c, d, e, f, g, h, i, j, k, 0))

ans = bfs(table, tomato)
flag = False
for a in range(len_list[10]):
    for b in range(len_list[9]):
        for c in range(len_list[8]):
            for d in range(len_list[7]):
                for e in range(len_list[6]):
                    for f in range(len_list[5]):
                        for g in range(len_list[4]):
                            for h in range(len_list[3]):
                                for i in range(len_list[2]):
                                    for j in range(len_list[1]):
                                        for k in range(len_list[0]):
                                            if table[a][b][c][d][e][f][g][h][i][j][k] == 0:
                                                flag = True
                                                break
                                        if flag:
                                            break
                                    if flag:
                                        break
                                if flag:
                                    break
                            if flag:
                                break
                        if flag:
                            break
                    if flag:
                        break
                if flag:
                    break
            if flag:
                break
        if flag:
            break
    if flag:
        break

if flag:
    print(-1)
else:
    print(ans)