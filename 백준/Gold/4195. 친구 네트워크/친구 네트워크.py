import sys
input = sys.stdin.readline

def _union(A, B):
    A_parent = _find(A)
    B_parent = _find(B)

    if A_parent == B_parent:
        return
    if parent[A_parent] < parent[B_parent]:
        parent[A_parent] += parent[B_parent]
        count[A_parent] += count[B_parent]
        count[B_parent] = 0
        parent[B_parent] = A_parent
        
    else:
        parent[B_parent] += parent[A_parent]
        count[B_parent] += count[A_parent]
        count[A_parent] = 0
        parent[A_parent] = B_parent

def _find(node):
    if parent[node] < 0:
        return node
    parent[node] = _find(parent[node])
    return parent[node]

T = int(input())

for _ in range(T):
    N = int(input())
    name_dic = {}
    parent = [-1 for _ in range(200001)]
    count = [0 for _ in range(200001)]
    index = 1
    for _ in range(N):
        name = list(input().split())
        for i in range(2):
            if name[i] not in name_dic:
                name_dic[name[i]] = index
                count[index] += 1
                index += 1
        _union(name_dic[name[0]], name_dic[name[1]])
        print(count[_find(name_dic[name[0]])])