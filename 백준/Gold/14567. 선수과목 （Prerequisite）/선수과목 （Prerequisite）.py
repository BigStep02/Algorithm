from collections import deque
import sys
input = sys.stdin.readline

def topology_sort():
    queue = deque()
    for i in range(1, len(deg)):
        if deg[i] == 0:
            queue.append(i)
            answer[i] += 1
    
    while queue:
        node = queue.popleft()
        for next_node in graph[node]:
            deg[next_node] -= 1
            if deg[next_node] == 0:
                answer[next_node] = answer[node] + 1
                queue.append(next_node)


N, M = map(int, input().split())
graph = [[] for _ in range(N + 1)]
deg = [0 for _ in range(N + 1)]
answer = [0 for _ in range(N + 1)]

for _ in range(M):
    A, B = map(int, input().split())
    graph[A].append(B)
    deg[B] += 1

topology_sort()
answer = answer[1:]
print(*answer)