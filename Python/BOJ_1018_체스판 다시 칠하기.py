import sys

n, m = map(int, sys.stdin.readline().split())
chess = []
for i in range(n):
    chess.append(sys.stdin.readline().rstrip())

minimum = n * m
for j in range(n - 7):
    for k in range(m - 7):
        
        w_first = 0
        char = 'W'
        change = 0
        for a in range(j, j + 8):
            if change // 8 == 1:
                if char == 'W':
                    char = 'B'
                    change = 0
                else:
                    char = 'W'
                    change = 0
            for b in range(k, k + 8):
                if chess[a][b] != char:
                    w_first += 1
                if char == 'W':
                    char = 'B'
                elif char == 'B':
                    char = 'W'
                change += 1
        
        b_first = 0
        char = 'B'
        change = 0
        for c in range(j, j + 8):
            if change // 8 == 1:
                if char == 'B':
                    char = 'W'
                    change = 0
                else:
                    char = 'B'
                    change = 0
            for d in range(k, k + 8):
                if chess[c][d] != char:
                    b_first += 1
                if char == 'B':
                    char = 'W'
                elif char == 'W':
                    char = 'B'
                change += 1
                    
        if min(w_first, b_first) < minimum:
            minimum = min(w_first, b_first)

print(minimum)