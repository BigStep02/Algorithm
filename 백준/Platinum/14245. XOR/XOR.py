import sys
input = sys.stdin.readline

def segment_init(base):
    nums = list(map(int, input().split()))
    for i in range(base, base + len(nums)):
        segment[i][0] = nums[i - base]
    
    for i in range(base - 1, 0, -1):
        segment[i][0] = (segment[i * 2][0] ^ segment[i * 2 + 1][0])

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
    segment[node][0] = (segment[node * 2][0] ^ segment[node * 2 + 1][0])

def segment_check(check_index, node_left, node_right, node):
    propagation(node, node_left, node_right)
    if node_left == node_right:
        return segment[node][0]
    
    mid = (node_left + node_right) // 2
    if check_index <= mid:
        return segment_check(check_index, node_left, mid, node * 2)
    else:
        return segment_check(check_index, mid + 1, node_right, node * 2 + 1)

def propagation(node, node_left, node_right):
    if segment[node][1] != 0:
        if (node_right - node_left + 1) % 2 == 1:
            segment[node][0] ^= segment[node][1]
        if node_left != node_right:
            segment[node * 2][1] ^= segment[node][1]
            segment[node * 2 + 1][1] ^= segment[node][1]
        segment[node][1] = 0

N = int(input())
base = 1

while base < N:
    base <<= 1

segment = [[0, 0] for _ in range(base * 2)]

segment_init(base)

M = int(input())

for _ in range(M):
    nums = list(map(int, input().split()))
    if nums[0] == 1:
        start_index, end_index, change = nums[1] + 1, nums[2] + 1, nums[3]
        segment_update(start_index, end_index, 1, base, 1, change)
    else:
        check_index = nums[1] + 1
        print(segment_check(check_index, 1, base, 1))