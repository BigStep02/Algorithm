import sys
input = sys.stdin.readline

def segment_find(start_index, end_index):
    answer = 10 ** 9
    while start_index <= end_index:
        if start_index % 2 == 1:
            answer = min(answer, segment[start_index])
            start_index += 1
        if end_index % 2 == 0:
            answer = min(answer, segment[end_index])
            end_index -= 1
        start_index //= 2
        end_index //= 2
    
    return answer

def segment_init():
    for i in range(base, base + N):
        A = int(input())
        segment[i] = A

def segment_prefix_min():
    for i in range(base - 1, 0, -1):
        segment[i] = min(segment[i * 2], segment[i * 2 + 1])

N, M = map(int, input().split())
base = 1
while base < N:
    base <<= 1

segment = [0 for _ in range(base * 2)]

segment_init()
segment_prefix_min()

for _ in range(M):
    a, b = map(int, input().split())
    start_index = a + base - 1
    end_index = b + base - 1
    print(segment_find(start_index, end_index))