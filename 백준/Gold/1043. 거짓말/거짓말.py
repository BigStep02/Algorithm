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

N, M = map(int, input().split())
real_man = list(map(int, input().split()))[1:]
parent = [-1 for _ in range(N + 1)]

if len(real_man) > 1:
    for i in range(1, len(real_man)):
        _union(real_man[i - 1], real_man[i])

parties = []
for _ in range(M):
    a = list(map(int, input().split()))
    parties.append(a[1:])

for party in parties:
    person = party[0]
    for people in party[1:]:
        _union(person, people)

cnt = 0

for party in parties:
    state = True
    for people in party:
        if _find(people) in [_find(x) for x in real_man]:
            state = False
    if state == True:
        cnt += 1

print(cnt)