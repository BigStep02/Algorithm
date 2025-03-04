import sys
input = sys.stdin.readline

def _union(A, B, cost):
    global answer
    A_parent = _find(A)
    B_parent = _find(B)
    
    if A_parent == B_parent:
        return
    if parent[A_parent] < parent[B_parent]:
        parent[A_parent] += parent[B_parent]
        parent[B_parent] = A_parent
        answer += cost
    else:
        parent[B_parent] += parent[A_parent]
        parent[A_parent] = B_parent
        answer += cost

def _find(node):
    if parent[node] < 0:
        return node
    parent[node] = _find(parent[node])
    return parent[node]

N = int(input())
M = int(input())
edge = []
parent = [-1 for _ in range(N + 1)]

for _ in range(M):
    a, b, c = map(int, input().split())
    edge.append([a, b, c])

edge.sort(key = lambda x : x[2])
answer = 0
for i in range(len(edge)):
    _union(edge[i][0], edge[i][1], edge[i][2])

print(answer)