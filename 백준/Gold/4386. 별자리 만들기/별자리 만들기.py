import sys, math
input = sys.stdin.readline
sys.setrecursionlimit(10**5)

def check_dist(x1, y1, x2, y2): # 좌표 평면 위의 두 점 사이 거리 구하기 (유클리드 거리)
    return math.sqrt((abs(x1 - x2)) ** 2 + (abs(y1 - y2)) ** 2)

def _union(A, B, dist): # 같은 그룹인지 체크 (유니온 파인드)
    global answer
    A_parent = _find(A)
    B_parent = _find(B)

    if A_parent == B_parent:
        return
    if parent[A_parent] < parent[B_parent]:
        parent[B_parent] = A_parent
        parent[A_parent] -=1
        answer += dist
    else:
        parent[A_parent] = B_parent
        parent[B_parent] -= 1
        answer += dist

def _find(node): # 속해있는 그룹의 루트 찾기
    if parent[node] < 0:
        return node
    parent[node] = _find(parent[node])
    return parent[node]

N = int(input())
stars = [list(map(float, input().split())) for i in range(N)]
parent = [-1 for _ in range(N)]

edge = []

for i in range(len(stars)):
    for j in range(i + 1, len(stars)):
        dist = check_dist(stars[i][0], stars[i][1], stars[j][0], stars[j][1])
        edge.append([i, j, dist])

edge.sort(key = lambda x : x[2])
answer = 0
for A, B, dist in edge:
    _union(A, B, dist)

print(answer)