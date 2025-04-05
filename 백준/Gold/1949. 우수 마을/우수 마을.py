import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 5)

def DFS(node):
    for nextNode in graph[node]:
        if visited[nextNode] != 0: continue
        visited[nextNode] = 1
        DFS(nextNode)
        dp[node][0] += max(dp[nextNode])
        dp[node][1] += dp[nextNode][0]

N = int(input())
people = list(map(int, input().split()))
graph = [[] for _ in range(N + 1)]
visited = [0 for _ in range(N + 1)]
dp = [[0, 0] for _ in range(N + 1)]

for _ in range(N - 1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(1, N + 1):
    dp[i][1] = people[i - 1]

visited[1] = 1
DFS(1)

print(max(dp[1]))