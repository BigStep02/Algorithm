import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 5)

def DFS(node):

    for next_node in graph[node]:
        if visited[next_node] != -1: continue
        visited[next_node] = visited[node] + 1
        DFS(next_node)

N, M, R = map(int, input().split())
graph = [[] for _ in range(N + 1)]
visited = [-1 for _ in range(N + 1)]

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(1, N + 1):
    if len(graph[i]) == 0: continue
    graph[i].sort()

visited[R] = 0
DFS(R)

for x in visited[1:]:
    print(x)