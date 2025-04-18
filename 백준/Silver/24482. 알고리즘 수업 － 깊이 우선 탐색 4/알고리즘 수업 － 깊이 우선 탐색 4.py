import sys
input = sys.stdin.readline

sys.setrecursionlimit(10 ** 5)

def DFS(node, high):
    level[node] = high
    for nextNode in graph[node]:
        if visited[nextNode] != -1: continue
        visited[nextNode] = 1
        DFS(nextNode, high + 1)

N, M, R = map(int, input().split())
graph = [[] for _ in range(N + 1)]
visited = [-1 for _ in range(N + 1)]
level = [-1 for _ in range(N + 1)]

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(1, N + 1):
    graph[i].sort(reverse = True)

visited[R] = 0
DFS(R, 0)

for x in level[1:]:
    print(x)