import sys
input = sys.stdin.readline

def _union(A, B):
    A_parent = _find(A)
    B_parent = _find(B)

    if A_parent == B_parent:
        return
    if parent[A_parent] < parent[B_parent]:
        parent[A_parent] += parent[B_parent]
        parent[B_parent] = A_parent
    else:
        parent[B_parent] += parent[A_parent]
        parent[A_parent] = B_parent

def _find(node):
    if parent[node] < 0:
        return node
    parent[node] = _find(parent[node])
    return parent[node]

Test_case = int(input())

for i in range(1, Test_case + 1):
    N = int(input())
    k = int(input())
    parent = [-1 for _ in range(N + 1)]
    for _ in range(k):
        a, b = map(int, input().split())
        _union(a, b)
    k = int(input())
    print(f'Scenario {i}:')
    for i in range(k):
        a, b = map(int, input().split())
        if _find(a) == _find(b):
            print(1)
        else:
            print(0)
    print()