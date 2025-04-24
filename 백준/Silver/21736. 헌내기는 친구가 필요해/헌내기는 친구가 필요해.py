from collections import deque
import sys
input = sys.stdin.readline

def BFS():
    global N, M, cnt
    while queue:
        dx, dy = queue.popleft()
        for x, y in [[1, 0], [0, 1], [-1, 0], [0, -1]]:
            nx = dx + x
            ny = dy + y
            if nx < 0 or nx >= N or ny < 0 or ny >= M : continue
            if visited[nx][ny] != 0 or board[nx][ny] == "X" : continue
            if board[nx][ny] == "P": cnt += 1
            visited[nx][ny] = 1
            queue.append([nx, ny])

N, M = map(int, input().split())

board = [list(map(str, input().rstrip())) for _ in range(N)]
visited = [[0 for _ in range(M)] for _ in range(N)]
queue = deque()

for i in range(N):
    for j in range(M):
        if board[i][j] == "I":
            queue.append([i, j])
            visited[i][j] = 1

cnt = 0
BFS()

if cnt != 0:
    print(cnt)
else: print("TT")