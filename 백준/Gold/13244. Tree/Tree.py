import sys
input = sys.stdin.readline

def _union(A, B):
    A_parent = _find(A)
    B_parent = _find(B)

    if A_parent == B_parent:
        return False
    
    if parent[A_parent] < parent[B_parent]:
        parent[A_parent] += parent[B_parent]
        parent[B_parent] = A_parent
    else:
        parent[B_parent] += parent[A_parent]
        parent[A_parent] = B_parent

    return True

def _find(node):
    if parent[node] < 0:
        return node
    
    parent[node] = _find(parent[node])
    return parent[node]

def DFS(node):
    for next_node in graph[node]:
        if visited[next_node] != 0: continue
        visited[next_node] = 1
        DFS(next_node)

testCase = int(input())

for _ in range(testCase):
    N = int(input())
    edge = int(input())
    state = True
    parent = [-1 for _ in range(N + 1)]
    graph = [[] for _ in range(N + 1)]

    for _ in range(edge):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
        if not _union(a, b):
            state = False

    if not state: 
        print("graph")
        continue

    visited = [0 for _ in range(N + 1)]
    DFS(a)
    
    for i in range(1, len(visited)):
        if visited[i] == 0:
            state = False
            break

    if not state:
        print("graph")
        continue

    print("tree")