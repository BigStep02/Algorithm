import sys
sys.setrecursionlimit(10**5)

def _union(cost, a, b):
    global answer
    a_parent = _find(a)
    b_parent = _find(b)

    if a_parent == b_parent:
        return
    if parent[a_parent] < parent[b_parent]:
        parent[a_parent] = b_parent
        answer += cost
    else:
        parent[b_parent] = a_parent
        answer += cost

def _find(node):
    if parent[node] < 0:
        return node
    parent[node] = _find(parent[node])
    return parent[node]

N, M = map(int, input().split())
graph = [[] for _ in range(N + 1)]
parent = [-1 for _ in range(N + 1)]
edge = []

for i in range(M):
    a, b, c = map(int, input().split())
    graph[a].append([b, c])
    graph[b].append([a, c])
    edge.append([c, a, b])

edge.sort(key = lambda x : x[0])
answer = 0
for i in range(len(edge)):
    _union(edge[i][0], edge[i][1], edge[i][2])

print(answer)