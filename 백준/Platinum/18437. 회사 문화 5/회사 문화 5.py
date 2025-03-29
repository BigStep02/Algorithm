import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 5)

def Euler_Tour(node):
    global cnt
    cnt += 1
    inn[node] = cnt
    
    for next_node in graph[node]:
        if visited[next_node] != 0: continue
        visited[next_node] = 1
        Euler_Tour(next_node)
    
    out[node] = cnt

def segment_init():
    global base

    for i in range(base, base + len(inn) - 1):
        segment[i][0] = 1

    for i in range(base - 1, 0, -1):
        segment[i][0] = segment[i * 2][0] + segment[i * 2 + 1][0]

def segment_update(start_index, end_index, node_left, node_right, node, change):
    lazy_propagation(node, node_left, node_right)

    if start_index > node_right or end_index < node_left:
        return
    if start_index <= node_left and end_index >= node_right:
        if change == 1:
            segment[node][0] = (node_right - node_left + 1)
        else:
            segment[node][0] = 0
        
        if node_left != node_right:
            segment[node * 2][1] = change
            segment[node * 2 + 1][1] = change
        return
    
    mid = (node_left + node_right) // 2
    segment_update(start_index, end_index, node_left, mid, node * 2, change)
    segment_update(start_index, end_index, mid + 1, node_right, node * 2 + 1, change)
    segment[node][0] = segment[node * 2][0] + segment[node * 2 + 1][0]

def lazy_propagation(node, node_left, node_right):
    if segment[node][1] != None:
        if segment[node][1] == 1:
            segment[node][0] = (node_right - node_left + 1)
        else:
            segment[node][0] = 0

        if node_left != node_right:
            segment[node * 2][1] = segment[node][1]
            segment[node * 2 + 1][1] = segment[node][1]
        segment[node][1] = None

def segment_check(start_index, end_index, node_left, node_right, node):
    lazy_propagation(node, node_left, node_right)
    
    if start_index > node_right or end_index < node_left:
        return 0
    if start_index <= node_left and end_index >= node_right:
        return segment[node][0]

    mid = (node_left + node_right) // 2

    left = segment_check(start_index, end_index, node_left, mid, node * 2)
    right = segment_check(start_index, end_index, mid + 1, node_right, node * 2 + 1)

    return left + right    

N = int(input())

graph = [[] for _ in range(N + 1)]
edge = list(map(int, input().split()))
inn = [0 for _ in range(N + 1)]
out = [0 for _ in range(N + 1)]
visited = [0 for _ in range(N + 1)]

for i in range(1, N):
    graph[edge[i]].append(i + 1)

cnt = 0
visited[1] = 1
Euler_Tour(1)

M = int(input())

base = 1
while base < N:
    base <<= 1

segment = [[0, None] for _ in range(base * 2)]

segment_init()

for _ in range(M):
    a, b = map(int, input().split())
    if a == 1:
        segment_update(inn[b] + 1, out[b], 1, base, 1, 1)
    elif a == 2:
        segment_update(inn[b] + 1, out[b], 1, base, 1, 0)
    else:
        print(segment_check(inn[b] + 1, out[b], 1, base, 1))