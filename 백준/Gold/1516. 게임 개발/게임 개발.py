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
            dp[next_node] = max(dp[node], dp[next_node])
            if deg[next_node] == 0:
                queue.append(next_node)


N = int(input())
deg = [0 for _ in range(N + 1)]
graph = [[] for _ in range(N + 1)]
cost = [0 for _ in range(N + 1)]
dp = [0 for _ in range(N + 1)]

for i in range(1, N + 1):
    nums = list(map(int, input().split()))
    cost[i] = nums[0]
    for j in range(1, len(nums)):
        if nums[j] == -1:
            break
        graph[nums[j]].append(i)
        deg[i] += 1

topology_sort(dp)
for i in range(1, len(dp)):
    print(dp[i])