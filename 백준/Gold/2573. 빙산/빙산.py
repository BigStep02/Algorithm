from collections import deque
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 5)

def BFS(board, N, M):
    while queue:
        dx, dy = queue.popleft()
        for nx, ny in [[1, 0], [0, 1], [-1, 0], [0, -1]]:
            nx += dx
            ny += dy
            if nx < 0 or nx >= N or ny < 0 or ny >= M: continue
            if board[nx][ny] == 0 and board[dx][dy] != 0 and ice_check[nx][ny] == 0: 
                board[dx][dy] -= 1
                if board[dx][dy] == 0:
                    ice_check[dx][dy] = 1
            if visited[nx][ny] != 0 or board[nx][ny] <= 0: continue
            visited[nx][ny] = 1

def DFS(x, y, N, M):
    ice_visited[x][y] = 1
    for nx, ny in [[0, 1], [1, 0], [-1, 0], [0, -1]]:
        nx += x
        ny += y
        if nx < 0 or nx >= N or ny < 0 or ny >= M: continue
        if board[nx][ny] == 0 or ice_visited[nx][ny] != 0: continue
        DFS(nx, ny, N, M)

N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]

answer = 0
day = 1
while True:
    queue = deque()
    visited = [[0 for _ in range(M)] for _ in range(N)]
    ice_visited = [[0 for _ in range(M)] for _ in range(N)]
    ice_check = [[0 for _ in range(M)] for _ in range(N)]
    ice = []
    cnt = 0

    for i in range(N):
        for j in range(M):
            if board[i][j] != 0:
                ice.append([i, j])

    for x, y in ice:
        queue.append([x, y])
        visited[x][y] = 1

    BFS(board, N, M)

    for i in range(N):
        for j in range(M):
            if board[i][j] != 0 and ice_visited[i][j] == 0:
                cnt += 1
                DFS(i, j, N, M)
                if cnt >= 2:
                    break

    if cnt == 0:
        break
    if cnt >= 2:
        answer = day
        break
    day += 1

print(answer)