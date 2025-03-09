import sys
input = sys.stdin.readline

def segment_update(start_index, change):    
    while start_index >= 1:
        segment[start_index] += change
        start_index //= 2

def segment_partial_sum(start_index, end_index):
    answer = 0
    while start_index <= end_index:
        if start_index % 2 == 1:
            answer += segment[start_index]
            start_index += 1
        if end_index % 2 == 0:
            answer += segment[end_index]
            end_index -= 1
        start_index //= 2
        end_index //= 2
        
    return answer

N, M = map(int, input().split())
base = 1
while base < N:
    base <<= 1
segment = [0 for _ in range(base * 2)]

for _ in range(M):
    a, b, c = map(int, input().split())
    if a == 0:
        if b > c:
            b, c = c, b
        start_index, end_index = b + base - 1, c + base - 1
        print(segment_partial_sum(start_index, end_index))
    else:
        start_index = b + base - 1
        change = c - segment[start_index]
        segment[start_index] = c
        segment_update(start_index // 2, change)