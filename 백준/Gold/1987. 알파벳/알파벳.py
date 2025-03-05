import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**5)

def DFS(x, y, cost):
    global max_cost
    max_cost = max(max_cost, cost)

    for dx, dy in next_node:
        nx = x + dx
        ny = y + dy
        if nx < 0 or nx >= N or ny < 0 or ny >= M: continue
        if visited[ord(board[nx][ny]) - ord('A')] != 0: continue
        visited[ord(board[nx][ny]) - ord('A')] = 1
        DFS(nx, ny, cost + 1)
        visited[ord(board[nx][ny]) - ord('A')] = 0

  
N, M = map(int, input().split())
board = [input().rstrip() for _ in range(N)]
visited = [0 for _ in range(26)]
next_node = [[1, 0], [0, 1], [-1, 0], [0, -1]]
max_cost = 1
visited[ord(board[0][0]) - ord('A')] = 1
DFS(0, 0, 1)

print(max_cost)