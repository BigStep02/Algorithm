import sys
input = sys.stdin.readline

def _union(A, B, cost):
    global cnt
    answer = 0
    A_parent = _find(A)
    B_parent = _find(B)
    
    if A_parent == B_parent:
        return 0
    if parent[A_parent] < parent[B_parent]:
        parent[A_parent] += parent[B_parent]
        parent[B_parent] = A_parent
        if cost == 0:
            cnt += 1
            answer += cnt ** 2
    else:
        parent[B_parent] += parent[A_parent]
        parent[A_parent] = B_parent
        if cost == 0:
            cnt += 1
            answer += cnt ** 2
    return answer

def _find(node):
    if parent[node] < 0:
        return node
    parent[node] = _find(parent[node])
    return parent[node]
    

N, M = map(int, input().split())
edge = [list(map(int, input().split())) for _ in range(M + 1)]
parent = [-1 for _ in range(N + 1)]
min_answer = 0
max_answer = 0

edge.sort(key = lambda x : -x[2])
cnt = 0
for i in range(len(edge)):
    min_answer = max(min_answer, _union(edge[i][0], edge[i][1], edge[i][2]))
parent = [-1 for _ in range(N + 1)]
edge.sort(key = lambda x : x[2])
cnt = 0
for i in range(len(edge)):
    max_answer = max(max_answer, _union(edge[i][0], edge[i][1], edge[i][2]))

print(max_answer - min_answer)