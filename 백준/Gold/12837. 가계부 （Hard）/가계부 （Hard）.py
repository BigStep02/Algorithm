import sys
input = sys.stdin.readline

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

def segment_update(start_index, change):
    while start_index >= 1:
        segment[start_index] += change
        start_index //= 2

N, M = map(int, input().split())
base = 1

while base < N:
    base <<= 1

segment = [0 for _ in range(base * 2)]

for _ in range(M):
    nums = list(map(int, input().split()))
    if nums[0] == 1:
        start_index, change = nums[1] + base - 1, nums[2]
        segment_update(start_index, change)
    else:
        start_index, end_index = nums[1] + base - 1, nums[2] + base - 1
        print(segment_partial_sum(start_index, end_index))