import sys
input = sys.stdin.readline

def _union(A, B, cost):
    global answer, max_cost
    A_parent = _find(A)
    B_parent = _find(B)

    if A_parent == B_parent:
        return
    if parent[A_parent] < parent[B_parent]:
        parent[A_parent] += parent[B_parent]
        parent[B_parent] = A_parent
        answer += cost
        max_cost = max(max_cost, cost)
    else:
        parent[B_parent] += parent[A_parent]
        parent[A_parent] = B_parent
        answer += cost
        max_cost = max(max_cost, cost)

    

def _find(node):
    if parent[node] < 0:
        return node
    parent[node] = _find(parent[node])
    return parent[node]
    

N, M = map(int, input().split())
edge = []
parent = [-1 for _ in range(N + 1)]

for _ in range(M):
    a, b, c = map(int, input().split())
    edge.append([a, b, c])

edge.sort(key = lambda x : x[2])
answer = 0
max_cost = 0

for x, y, cost in edge:
    _union(x, y, cost)

print(answer - max_cost)