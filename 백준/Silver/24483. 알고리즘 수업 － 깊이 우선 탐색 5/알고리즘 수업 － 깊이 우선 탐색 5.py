import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 5)

def DFS(node, high):
    global cnt
    visited[node] = cnt
    level[node] = high
    cnt += 1

    for nextNode in graph[node]:
        if visited[nextNode] != -1: continue
        DFS(nextNode, high + 1)

N, M, R = map(int, input().split())
graph = [[] for _ in range(N + 1)]
visited = [-1 for _ in range(N + 1)]
level = [0 for _ in range(N + 1)]

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(1, N + 1):
    graph[i].sort()

cnt = 1
DFS(R, 0)

answer = 0
for i in range(1, N + 1):
    answer += visited[i] * level[i]

print(answer)