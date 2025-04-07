import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 5)

def _union(A, B):
    global cnt

    aParent = _find(A)
    bParent = _find(B)

    if aParent == bParent:
        return
    
    if parent[aParent] < parent[bParent]:
        parent[aParent] += parent[bParent]
        parent[bParent] = aParent
        cnt += 1
    else:
        parent[bParent] += parent[aParent]
        parent[aParent] = bParent
        cnt += 1

def _find(node):
    if parent[node] < 0:
        return node
    
    parent[node] = _find(parent[node])
    return parent[node]

testCase = int(input())

for _ in range(testCase):
    N, M = map(int, input().split())
    parent = [-1 for _ in range(N + 1)]
    cnt = 0

    for _ in range(M):
        a, b = map(int, input().split())
        _union(a, b)

    print(cnt)