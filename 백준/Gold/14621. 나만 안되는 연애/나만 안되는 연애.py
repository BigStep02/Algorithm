def _union(A, B, dist):
    global answer, cnt
    A_parent = _find(A)
    B_parent = _find(B)

    if A_parent == B_parent:
        return
    if parent[A_parent] < parent[B_parent]:
        answer += dist
        cnt += 1
        parent[A_parent] += parent[B_parent]
        parent[B_parent] = A_parent
    else:
        answer += dist
        cnt += 1
        parent[B_parent] += parent[A_parent]
        parent[A_parent] = B_parent

def _find(node):
    if parent[node] < 0:
        return node
    parent[node] = _find(parent[node])
    return parent[node]

N, M = map(int, input().split())
college = list(map(str, input().split()))
parent = [-1 for _ in range(N + 1)]
edge = []

for _ in range(M):
    a, b, c = map(int, input().split())
    edge.append([a, b, c])

edge.sort(key = lambda x : x[2])

answer = 0
cnt = 0
for i in range(len(edge)):
    if college[edge[i][0] - 1] == college[edge[i][1] - 1]:
        continue
    _union(edge[i][0], edge[i][1], edge[i][2])

if cnt != N - 1:
    print(-1)
else:
    print(answer)