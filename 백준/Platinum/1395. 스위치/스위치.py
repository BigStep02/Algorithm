import sys
input = sys.stdin.readline

def segment_update(start_index, end_index, node_left, node_right, node, change):
    propagation(node, node_left, node_right)
    if start_index > node_right or end_index < node_left:
        return
    if start_index <= node_left and end_index >= node_right:
        segment[node][1] ^= change
        propagation(node, node_left, node_right)
        return
    
    mid = (node_left + node_right) // 2
    segment_update(start_index, end_index, node_left, mid, node * 2, change)
    segment_update(start_index, end_index, mid + 1, node_right, node * 2 + 1, change)
    segment[node][0] = segment[node * 2][0] + segment[node * 2 + 1][0]

def segment_check(start_index, end_index, node_left, node_right, node):
    propagation(node, node_left, node_right)
    if start_index > node_right or end_index < node_left:
        return 0
    if start_index <= node_left and end_index >= node_right:
        return segment[node][0]
    
    mid = (node_left + node_right) // 2
    left = segment_check(start_index, end_index, node_left, mid, node * 2)
    right = segment_check(start_index, end_index, mid + 1, node_right, node * 2 + 1)

    return left + right

def propagation(node, node_left, node_right):
    if segment[node][1] != 0:
        segment[node][0] = (node_right - node_left + 1) - segment[node][0]
        if node_left != node_right:
            segment[node * 2][1] ^= segment[node][1]
            segment[node * 2 + 1][1] ^= segment[node][1]
        segment[node][1] = 0

N, M = map(int, input().split())

base = 1
while base < N:
    base <<= 1

segment = [[0, 0] for _ in range(base * 2)]

for _ in range(M):
    a, b, c = map(int, input().split())
    if a == 0:
        segment_update(b, c, 1, base, 1, 1)
    if a == 1:
        print(segment_check(b, c, 1, base, 1))