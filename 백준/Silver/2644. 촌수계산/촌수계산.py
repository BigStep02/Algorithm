import sys
input = sys.stdin.readline

def DFS(node):
    for nextNode in graph[node]:
        if visited[nextNode] != -1: continue
        visited[nextNode] = visited[node] + 1
        DFS(nextNode)

N = int(input())
target1, target2 = map(int, input().split())
M = int(input())
graph = [[] for _ in range(N + 1)]
visited = [-1 for _ in range(N + 1)]

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

visited[target1] = 1
DFS(target1)

if visited[target2] == -1:
    print(-1)
else: print(visited[target2] - 1)