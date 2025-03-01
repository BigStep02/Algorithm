from collections import deque

def Topology_sory():
    while len(queue): # queue에 원소가 없을 때 까지 반복
        node = queue.popleft() # queue에서 degree가 0인 노드 하나 꺼내기
        for x in graph[node]: # 해당 노드와 연결 된 모든 노드와 간선 끊기
            deg[x] -= 1 
            if deg[x] == 0:
                queue.append(x)
        answer.append(node)

N, M = map(int, input().split())
graph = [[] for _ in range(N + 1)]
deg = [0 for _ in range(N + 1)] # degree 리스트
queue = deque()

for i in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    deg[b] += 1 # 간선을 통해 deg 리스트 채우기

for i in range(1, len(deg)):
    if deg[i] == 0:
        queue.append(i) # 위상 정렬을 위해 degree가 0 인 것들을 q에 append.

answer = []
Topology_sory() # 위상 정렬.
print(*answer)