from collections import deque
import sys
input = sys.stdin.readline

def BFS(queue, visited, board, i, j, N, L, R):
    union_contry = 1
    union_size = board[i][j]
    union = [[i, j]]
    while queue:
        nx, ny = queue.popleft()
        for x, y in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
            dx = nx + x
            dy = ny + y
            if dx < 0 or dx >= N or dy < 0 or dy >= N: continue
            if visited[dx][dy] != 0: continue
            if L <= abs(board[nx][ny] - board[dx][dy]) <= R:
                union_contry += 1
                union_size += board[dx][dy]
                union.append([dx, dy])
                visited[dx][dy] = 1
                queue.append([dx, dy])

    if union_contry > 1:
        for x, y in union:
            board[x][y] = union_size // union_contry
        return True
    
    return False
                

N, L, R = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
queue = deque()
answer = 0

while True:

    move = False
    visited = [[0 for _ in range(N)] for _ in range(N)]
    
    for i in range(N):
        for j in range(N):
            if visited[i][j] == 0:
                queue.append([i, j])
                visited[i][j] = 1
                if BFS(queue, visited, board, i, j, N, L, R):
                    move = True

    if move == False:
        break
    
    answer += 1

print(answer)