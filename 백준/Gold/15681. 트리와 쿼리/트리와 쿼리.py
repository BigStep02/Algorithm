import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 5)

def DFS(node, child):
    dp[node] = 1

    for nextNode in graph[node]:
        if visited[nextNode] != 0: continue
        visited[nextNode] = 1  
        DFS(nextNode, child + 1)
        dp[node] += dp[nextNode]

N, Root, Q = map(int, input().split())

graph = [[] for _ in range(N + 1)]
visited = [0 for _ in range(N + 1)]

for _ in range(N - 1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

dp = [0 for _ in range(N + 1)]

visited[Root] = 1
DFS(Root, 0)

for _ in range(Q):
    target = int(input())
    print(dp[target])