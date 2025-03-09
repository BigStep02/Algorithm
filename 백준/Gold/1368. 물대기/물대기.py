import sys
input = sys.stdin.readline

def _union(A, B, cost):
    global answer
    A_parent = _find(A)
    B_parent = _find(B)

    if A_parent == B_parent:
        return
    if parent[A_parent] < parent[B_parent]:
        answer += cost
        parent[A_parent] += parent[B_parent]
        parent[B_parent] = A_parent
    else :
        answer += cost
        parent[B_parent] += parent[A_parent]
        parent[A_parent] = B_parent       

def _find(node):
    if parent[node] < 0:
        return node
    parent[node] = _find(parent[node])
    return parent[node]

N = int(input())

parent = [-1 for _ in range(N + 1)]
self_cost = [int(input()) for _ in range(N)]
edge = []

for i in range(1, N + 1):
    nums = list(map(int, input().split()))
    for j in range(len(nums)):
        if nums[j] == 0:
            continue
        edge.append([i, j + 1, nums[j]])

for i in range(N):
    edge.append([0, i + 1, self_cost[i]])

edge.sort(key = lambda x : x[2])
answer = 0

for i in range(len(edge)):
    _union(edge[i][0], edge[i][1], edge[i][2])

print(answer)