import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 5)

def Euler_tour(node):
    global cnt
    cnt += 1
    inn[node] = cnt
    for next_node in graph[node]:
        if visited[next_node] == 1: continue
        visited[next_node] = 1
        Euler_tour(next_node)
    out[node] = cnt

def segment_init(base):
    for i in range(1, N + 1):
        index = inn[i] + base - 1
        segment[index][0] = money[i]

    for i in range(base - 1, 0, -1):
        segment[i][0] = segment[i * 2][0] + segment[i * 2 + 1][0]

def segment_update(start_index, end_index, node_left, node_right, node, change):
    propagation(node, node_left, node_right)
    if start_index > node_right or end_index < node_left:
        return
    if start_index <= node_left and end_index >= node_right:
        segment[node][1] += change
        propagation(node, node_left, node_right)
        return
    
    mid = (node_left + node_right) // 2
    segment_update(start_index, end_index, node_left, mid, node * 2, change)
    segment_update(start_index, end_index, mid + 1, node_right, node * 2 + 1, change)
    segment[node][0] = segment[node * 2][0] + segment[node * 2 + 1][0]

def propagation(node, node_left, node_right):
    if segment[node][1] != 0:
        segment[node][0] += segment[node][1] * (node_right - node_left + 1)
        if node_left != node_right:
            segment[node * 2][1] += segment[node][1]
            segment[node * 2 + 1][1] += segment[node][1]
        segment[node][1] = 0

def segment_check(check_index, node_left, node_right, node):
    propagation(node, node_left, node_right)
    if node_left == node_right:
        return segment[node][0]
    
    mid = (node_left + node_right) // 2
    if check_index <= mid:
        return segment_check(check_index, node_left, mid, node * 2)
    else:
        return segment_check(check_index, mid + 1, node_right, node * 2 + 1)

N, M = map(int, input().split())
graph = [[] for _ in range(N + 1)]
inn = [0 for _ in range(N + 1)]
out = [0 for _ in range(N + 1)]
visited = [0 for _ in range(N + 1)]
money = [0 for _ in range(N + 1)]

base = 1
while base < N:
    base <<= 1

segment = [[0, 0] for _ in range(base * 2)]

for i in range(1, N + 1):
    if i == 1:
        a = int(input())
        money[i] = a
        continue
    a, b = map(int, input().split())
    graph[b].append(i)
    money[i] = a

cnt = 0
visited[1] = 1
Euler_tour(1)

segment_init(base)

for _ in range(M):
    nums = list(input().split())
    if nums[0] == 'p':
        nums[1], nums[2] = int(nums[1]), int(nums[2])
        start_index, end_index, change = inn[nums[1]], out[nums[1]], nums[2]
        segment_update(start_index + 1, end_index, 1, base, 1, change)
    else:
        nums[1] = int(nums[1])
        check_index = inn[nums[1]]
        print(segment_check(check_index, 1, base, 1))