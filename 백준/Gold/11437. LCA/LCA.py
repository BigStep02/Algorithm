import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 5)

def DFS(node, high):
    level[node] = high

    for nextNode in graph[node]:
        if visited[nextNode] != 0: continue
        parent[nextNode] = node
        visited[node] = 1
        DFS(nextNode, high + 1)

def LCA(node1, node2):
    while level[node1] > level[node2]:
        node1 = parent[node1]

    while level[node2] > level[node1]:
        node2 = parent[node2]

    while node1 != node2:
        node1 = parent[node1]
        node2 = parent[node2]

    return node1

N = int(input())
parent = [0 for _ in range(N + 1)]
level = [0 for _ in range(N + 1)]
graph = [[] for _ in range(N + 1)]
visited = [0 for _ in range(N + 1)]

for _ in range(N - 1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
    parent[a] = b
    parent[b] = a

visited[1] = 1
DFS(1, 1)

M = int(input())

for _ in range(M):
    a, b = map(int, input().split())
    print(LCA(a, b))