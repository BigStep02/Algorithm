import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**5)

def _union(A, B, cost):
    global answer
    A_parent = _find(A)
    B_parent = _find(B)
    
    if A_parent == B_parent:
        return
    if A_parent < B_parent:
        parent[B_parent] = A_parent
        A_parent -= 1
        answer += cost
    else:
        parent[A_parent] = B_parent
        A_parent -= 1
        answer += cost

def _find(node):
    if parent[node] < 0:
        return node
    parent[node] = _find(parent[node])
    return parent[node]

while True:
    N, M = map(int, input().split())
    if N + M == 0:
        sys.exit()
    edge = []
    parent = [-1 for _ in range(N)]
    edge_sum = 0

    for _ in range(M):
        a, b, c = map(int, input().split())
        edge_sum += c
        edge.append([a, b, c])

    edge.sort(key = lambda x : x[2])
    answer = 0

    for A, B, cost in edge:
        _union(A, B, cost)

    print(edge_sum - answer)