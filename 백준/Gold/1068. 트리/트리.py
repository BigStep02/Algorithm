import sys
input = sys.stdin.readline

def DFS(node, M):
    global cnt
    if node == M:
        return

    if len(graph[node]) == 0:
        cnt += 1
        return

    for next_node in graph[node]:
        if visited[next_node] == 1: continue
        visited[next_node] = 1
        DFS(next_node, M)

N = int(input())
graph = [[] for _ in range(N)]
visited = [0 for _ in range(N)]
root = 0

edge = list(map(int, input().split()))
M = int(input())

for i in range(len(edge)):
    if i == M:
        if edge[i] == -1:
            root = i
        continue
    if edge[i] == -1:
        root = i
        continue
    graph[edge[i]].append(i)

if root == M:
    print(0)
    sys.exit()

visited[root] = 1
cnt = 0
DFS(root, M)

print(cnt)