import sys
input = sys.stdin.readline

def segment_update(start_index, change):
    while start_index >= 1:
        segment[start_index] += change
        start_index //= 2

def segment_partial_sum(start_index, end_index):
    partial_sum = 0
    while start_index <= end_index:
        if start_index % 2 == 1:
            partial_sum += segment[start_index]
            start_index += 1
        if end_index % 2 == 0:
            partial_sum += segment[end_index]
            end_index -= 1
        start_index //= 2
        end_index //= 2

    return partial_sum

def segment_init(base, N):
    nums = list(map(int, input().split()))
    for i in range(base, base + N):
        segment[i] = nums[i - base]

    for i in range(base - 1, 0, -1):
        segment[i] = segment[i * 2] + segment[i * 2 + 1]

N, M = map(int, input().split())
base = 1
while base < N:
    base <<= 1
segment = [0 for _ in range(base * 2)]

segment_init(base, N)

for _ in range(M):
    a, b, c, d = map(int, input().split())
    if a > b:
        a, b = b, a
    start_index = a + base - 1
    end_index = b + base - 1
    print(segment_partial_sum(start_index, end_index))
    start_index = c + base - 1
    change = d - segment[start_index]
    segment_update(start_index, change)