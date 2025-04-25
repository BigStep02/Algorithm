import sys
from collections import deque
sys.setrecursionlimit(10 ** 5)

def BFS():

    while queue:
        node = queue.popleft()
        for nextNode in graph[node]:
            if visited[nextNode] != -1: continue
            visited[nextNode] = visited[node] + 1
            queue.append(nextNode)

N, M = map(int, input().split())
graph = [[] for _ in range(N + 1)]

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

new_bridge = int(input())


for _ in range(new_bridge):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
    visited = [-1 for _ in range(N + 1)]
    visited[1] = 0
    queue = deque()
    queue.append(1)
    BFS()
    print(*visited[1:])
