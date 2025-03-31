import sys
input = sys.stdin.readline

def segment_update(start_index):
    start_index = start_index + base - 1
    segment[start_index] += 1
    start_index //= 2

    while start_index >= 1:
        segment[start_index] = segment[start_index * 2] + segment[start_index * 2 + 1]
        start_index //= 2

def segment_check(node_left, node_right, node, K):
    while node_left != node_right:
        mid = (node_left + node_right) // 2

        if segment[node * 2] >= K:
            node = node * 2
            node_right = mid
        else:
            K -= segment[node * 2]
            node = node * 2 + 1
            node_left = mid + 1

    segment[node] -= 1
    result = node_left

    while node >= 1:
        node //= 2
        segment[node] = segment[node * 2] + segment[node * 2 + 1]

    return result

def parent_update(node):
    node //= 2

    while node >= 1:
        segment[node] = segment[node * 2] + segment[node * 2 + 1]
        node //= 2

N = int(input())
base = 1

while base < 2000000:
    base <<= 1

segment = [0 for _ in range(base * 2)]

for _ in range(N):
    a, b = map(int, input().split())
    if a == 1:
        segment_update(b)
    else:
        print(segment_check(1, base, 1, b))