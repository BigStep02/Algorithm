import sys, bisect
input = sys.stdin.readline

def build(node, left, right):
    if left == right:
        mergeSortTree[node] = [nums[left]]
        return
    
    mid = (left + right) // 2

    build(node * 2, left, mid)
    build(node * 2 + 1, mid + 1, right)
    mergeSortTree[node] = sorted(mergeSortTree[node * 2] + mergeSortTree[node * 2 + 1])

def check(start_index, end_index, node_left, node_right, node, target):
    if start_index > node_right or end_index < node_left:
        return 0
    if start_index <= node_left and end_index >= node_right:
        return bisect.bisect_right(mergeSortTree[node], target)
    
    mid = (node_left + node_right) // 2
    return check(start_index, end_index, node_left, mid, node * 2, target) + check(start_index, end_index, mid + 1, node_right, node * 2 + 1, target)

N, M = map(int, input().split())
base = 1

while base < N:
    base <<= 1

mergeSortTree= [[] for _ in range(base * 2)]
nums = list(map(int, input().split()))

build(1, 0, N - 1)

for _ in range(M):
    a, b, c = map(int, input().split())
    a -= 1
    b -= 1
    answer = 0
    left = -1e9
    right = 1e9
    while left <= right:
        mid = (left + right) // 2
        if c <= check(a, b, 0, N - 1, 1, mid):
            answer = mid
            right = mid - 1 
        else:
            left = mid + 1

    print(int(answer))