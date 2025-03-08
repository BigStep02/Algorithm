from collections import deque
import sys
input = sys.stdin.readline

def topology_sort(deg, graph):
    while queue:
        node = queue.popleft()
        for next_node in graph[node]:
            deg[next_node] -= 1
            if deg[next_node] == 0:
                queue.append(next_node)
        answer.append(node)
            
N, M = map(int, input().split())
deg = [0 for _ in range(N + 1)]
graph = [[] for _ in range(N + 1)]

for i in range(M):
    nums = list(map(int, input().split()))
    for j in range(1, nums[0]):
        graph[nums[j]].append(nums[j + 1])
        deg[nums[j + 1]] += 1

queue = deque()
for i in range(1, len(deg)):
    if deg[i] == 0:
        queue.append(i)
answer = []
topology_sort(deg, graph)

if len(answer) == N:
    print(*answer)
else:
    print(0) 