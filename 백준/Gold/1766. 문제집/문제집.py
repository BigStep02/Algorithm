import sys, heapq
input = sys.stdin.readline

def topology_sort():
    while queue:
        node = heapq.heappop(queue)
        for next_node in graph[node]:
            deg[next_node] -= 1
            if deg[next_node] == 0:
                heapq.heappush(queue, next_node)
        answer.append(node)

N, M = map(int, input().split())
graph = [[] for _ in range(N + 1)]
deg = [0 for _ in range(N + 1)]

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    deg[b] += 1

queue = []
deg[0] = 10**10
for i in range(len(deg)):
    if deg[i] == 0:
        heapq.heappush(queue, i)
answer = []
topology_sort()
print(*answer)