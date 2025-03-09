from collections import deque
import sys
input = sys.stdin.readline

def topology_sort(dp):
    queue = deque()
    for i in range(1, len(deg)):
        if deg[i] == 0:
            queue.append(i)

    while queue:
        node = queue.popleft()
        dp[node] += cost[node]
        for next_node in graph[node]:
            deg[next_node] -= 1
            dp[next_node] = max(dp[next_node], dp[node])
            if deg[next_node] == 0:
                queue.append(next_node)

Test_case = int(input())

for _ in range(Test_case):
    N, M = map(int, input().split())
    cost = [0] + list(map(int, input().split()))
    graph = [[] for _ in range(N + 1)]
    deg = [0 for _ in range(N + 1)]
    dp = [0 for _ in range(N + 1)]

    for i in range(M):
        a, b = map(int, input().split())
        graph[a].append(b)
        deg[b] += 1

    target = int(input())
    topology_sort(dp)
    print(dp[target])