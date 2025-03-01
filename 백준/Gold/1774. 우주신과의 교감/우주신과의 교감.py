def dist_check(x1, y1, x2, y2):
    return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)

def _union(A, B, dist):
    global answer
    A_parent = _find(A)
    B_parent = _find(B)

    if A_parent == B_parent:
        return False
    if A_parent < B_parent:
        parent[A_parent] += parent[B_parent]
        parent[B_parent] = A_parent
        answer += dist
    else:
        parent[B_parent] += parent[A_parent]
        parent[A_parent] = B_parent
        answer += dist

def _find(node):
    if parent[node] < 0:
        return node
    parent[node] = _find(parent[node])
    return parent[node]

import sys, math
input = sys.stdin.readline
sys.setrecursionlimit(10**5)

N, M = map(int, input().split())
edge = []
dist_edge = []
parent = [-1 for _ in range(N + 1)]
answer = 0

for _ in range(N):
    a, b = map(int, input().split())
    edge.append([a, b, 0])

for _ in range(M):
    a, b = map(int, input().split())
    _union(a, b, 0)

for i in range(len(edge)):
    for j in range(i + 1, len(edge)):
        dist_edge.append([i + 1, j + 1, dist_check(edge[i][0], edge[i][1], edge[j][0], edge[j][1])])
dist_edge.sort(key = lambda x : x[2])

for i in range(len(dist_edge)):
    _union(dist_edge[i][0], dist_edge[i][1], dist_edge[i][2])

print(format(answer,'.2f'))