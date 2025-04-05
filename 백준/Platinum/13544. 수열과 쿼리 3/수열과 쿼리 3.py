import bisect
import sys
input = sys.stdin.readline

def merge_sort_tree_build(node, left, right):
    if left == right:
        mergeSortTree[node] = [nums[left]]
        return
    
    mid = (left + right) // 2
    merge_sort_tree_build(node * 2, left, mid)
    merge_sort_tree_build(node * 2 + 1, mid + 1, right)
    mergeSortTree[node] = sorted(mergeSortTree[node * 2] + mergeSortTree[node * 2 + 1])

def query(start_index, end_index, node_left, node_right, node, target):
    if start_index > node_right or end_index < node_left:
        return 0
    if start_index <= node_left and end_index >= node_right:
        idx = bisect.bisect_right(mergeSortTree[node], target)
        return len(mergeSortTree[node]) - idx
    mid = (node_left + node_right) // 2

    return query(start_index, end_index, node_left, mid, node * 2, target) + query(start_index, end_index, mid + 1, node_right, node * 2 + 1, target)

N = int(input())
base = 1

while base < N:
    base <<= 1

mergeSortTree = [[] for _ in range(base * 2)]
nums = list(map(int, input().split()))

merge_sort_tree_build(1, 0, N - 1)

M = int(input())

lastResult = 0
for _ in range(M):
    a, b, c = map(int, input().split())
    a, b, c = a ^ lastResult, b ^ lastResult, c ^ lastResult
    lastResult = query(a, b, 1, N, 1, c)
    print(lastResult)