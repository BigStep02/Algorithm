import sys
input = sys.stdin.readline

def segment_partial_min(start_index, end_index):
    answer = 10 ** 9
    while start_index <= end_index:
        if start_index % 2 == 1:
            answer = min(answer, segment_min[start_index])
            start_index += 1
        if end_index % 2 == 0:
            answer = min(answer, segment_min[end_index])
            end_index -= 1
        start_index //= 2
        end_index //= 2

    return answer

def segment_partial_max(start_index, end_index):
    answer = 0
    while start_index <= end_index:
        if start_index % 2 == 1:
            answer = max(answer, segment_max[start_index])
            start_index += 1
        if end_index % 2 == 0:
            answer = max(answer, segment_max[end_index])
            end_index -= 1
        start_index //= 2
        end_index //= 2

    return answer

def segment_init(base):
    global N
    for i in range(base, base + N):
        segment_min[i] = segment_max[i] = int(input())

    for i in range(base - 1, 0, -1):
        segment_min[i] = min(segment_min[i * 2], segment_min[i * 2 + 1])
        segment_max[i] = max(segment_max[i * 2], segment_max[i * 2 + 1])

N, M = map(int, input().split())
base = 1

while base < N:
    base <<= 1

segment_min = [0 for _ in range(base * 2)]
segment_max = [0 for _ in range(base * 2)]

segment_init(base)

for _ in range(M):
    a, b = map(int, input().split())
    start_index = a + base - 1
    end_index = b + base - 1
    print(segment_partial_min(start_index, end_index), end = " ")
    print(segment_partial_max(start_index, end_index))