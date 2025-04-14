import sys
input = sys.stdin.readline

def DFS(node):
   global cnt

   for nextNode in graph[node]:
       if visited[nextNode] != 0: continue
       visited[nextNode] = 1
       cnt += 1
       DFS(nextNode) 

N, M = map(int, input().split())
graph = [[] for _ in range(N + 1)]
visited = [0 for _ in range(N + 1)]
deg = [0 for _ in range(N + 1)]

for _ in range(M):
    a, b = map(str, input().split())
    graph[int(ord(a) - 64)].append(int(ord(b) - 64))
    deg[int(ord(b) - 64)] = 1

root = []

for i in range(1, len(deg)):
    if deg[i] == 0:
        root.append(i)
    
drug_catch = list(map(str, input().split()))

for x in drug_catch[1::]:
    visited[int(ord(x) - 64)] = 1

cnt = 0

for x in root:
    if visited[x]:
        continue
    visited[x] = 1
    DFS(x)

print(cnt)