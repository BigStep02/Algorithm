import sys
input = sys.stdin.readline

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
    node //= 2

    while node >= 1:
        segment[node] = segment[node * 2] + segment[node * 2 + 1]
        node //= 2

    return node_left

def segment_init(base, N):
    for i in range(base, base + N):
        segment[i] += 1

    for i in range(base - 1, 0, -1):
        segment[i] = segment[i * 2] + segment[i * 2 + 1]

N, K = map(int, input().split())
base = 1
while base < N:
    base <<= 1

segment = [0 for _ in range(base * 2)]
segment_init(base, N)

pos = K
result = []

for _ in range(N):
    result.append((segment_check(1, base, 1, pos)))

    if _ != N - 1:
        pos = (pos + K - 2) % (N - len(result)) + 1

print(f"<{', '.join(map(str, result))}>")