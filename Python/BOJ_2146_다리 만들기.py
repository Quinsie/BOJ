import sys
import collections

def numbering(board, number):
    queue = collections.deque()
    for i in range(N):
        for j in range(N):
            if board[i][j] == 1 and not visited[i][j]:
                queue.append((i, j))
                visited[i][j] = True
                board[i][j] = number
                distance[i][j] = 0

                while queue:
                    r, c = queue.popleft()
                    for d in range(4):
                        nr = r + dir[d][0]
                        nc = c + dir[d][1]
                        if 0 <= nr < N and 0 <= nc < N and not visited[nr][nc]:
                            if board[nr][nc] == 1:
                                queue.append((nr, nc))
                                visited[nr][nc] = True
                                board[nr][nc] = number
                                distance[nr][nc] = 0
                            
                            elif board[nr][nc] == 0:
                                sea.append((r, c, number))

                number += 1

def extend(board):
    answer = 1e9
    while sea:
        r, c, bridge = sea.popleft()
        for i in range(4):
            nr = r + dir[i][0]
            nc = c + dir[i][1]
            if 0 <= nr < N and 0 <= nc < N:
                if board[nr][nc] == 0:
                    board[nr][nc] = bridge
                    distance[nr][nc] = distance[r][c] + 1
                    sea.append((nr, nc, bridge))

                elif board[nr][nc] != bridge:
                    answer = min(answer, distance[r][c] + distance[nr][nc])

    return answer

input = sys.stdin.readline
N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]
visited = [[False] * N for _ in range(N)]
dir = [[-1, 0], [1, 0], [0, -1], [0, 1]]
distance = [[-1] * N for _ in range(N)]
sea = collections.deque()

numbering(board, 1)
print(extend(board))