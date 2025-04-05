import bisect
import sys
input = sys.stdin.readline

def build(node, left, right):
    if left == right:
        segment[node] = [nums[left]]
        return
    
    mid = (left + right) // 2
    build(node * 2, left, mid)
    build(node * 2 + 1, mid + 1, right)
    segment[node] = sorted(segment[node * 2] + segment[node * 2 + 1])

def segment_check(start_index, end_index, node_left, node_right, node, target):
    if start_index > node_right or end_index < node_left:
        return 0
    
    if start_index <= node_left and end_index >= node_right:
        idx = bisect.bisect_right(segment[node], target)
        return len(segment[node]) - idx

    mid = (node_left + node_right) // 2
    return segment_check(start_index, end_index, node_left, mid, node * 2, target) + segment_check(start_index, end_index, mid + 1, node_right, node * 2 + 1, target)

N = int(input())
base = 1

while base < N:
    base <<= 1

segment = [[] for _ in range(base * 2)]
nums = list(map(int, input().split()))

build(1, 0, N - 1)

M = int(input())

for _ in range(M):
    a, b, k = map(int, input().split())
    print(segment_check(a, b, 1, N, 1, k))