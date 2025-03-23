from collections import deque
import sys
input = sys.stdin.readline

def BFS(queue, board, visited, N, M):
    while queue:
        dx, dy, sword = queue.popleft()
        
        if dx == N - 1 and dy == M - 1:
            return visited[dx][dy][sword] - 1

        for x, y in [[1, 0], [0, 1], [-1, 0], [0, -1]]:
            nx, ny = dx + x, dy + y
            if nx < 0 or nx >= N or ny < 0 or ny >= M: continue

            if board[nx][ny] == 2 and visited[nx][ny][1] == 0:
                visited[nx][ny][1] = visited[dx][dy][sword] + 1
                queue.append([nx, ny, 1])
                continue

            if board[nx][ny] == 1:
                if sword == 1 and visited[nx][ny][1] == 0:
                    visited[nx][ny][1] = visited[dx][dy][1] + 1
                    queue.append([nx, ny, 1])
                continue

            if board[nx][ny] == 0 and visited[nx][ny][sword] == 0: 
                visited[nx][ny][sword] = visited[dx][dy][sword] + 1
                queue.append([nx, ny, sword])

    return -1        

N, M, time = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
visited = [[[0 for _ in range(2)]for _ in range(M)] for _ in range(N)] 

queue = deque()
queue.append([0, 0, 0])
visited[0][0][0] = 1
min_dist = BFS(queue, board, visited, N, M)

if min_dist == -1 or min_dist > time:
    print("Fail")
else: print(min_dist)