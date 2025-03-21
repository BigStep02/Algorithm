import sys
input = sys.stdin.readline

def DFS(start_node, end_node, cost):
    global answer
    if start_node == end_node:
        answer += cost
        return
    
    for next_node, c in graph[start_node]:
        if visited[next_node] != 0: continue
        visited[next_node] = 1
        DFS(next_node, end_node, cost + c)
    

N, M = map(int, input().split())
graph = [[] for _ in range(N + 1)]

for _ in range(N - 1):
    a, b, c = map(int, input().split())
    graph[a].append([b, c])
    graph[b].append([a, c])

for _ in range(M):
    visited = [0 for _ in range(N + 1)]
    a, b = map(int, input().split())
    answer = 0
    visited[a] = 1
    DFS(a, b, 0)
    print(answer)