import sys
input = sys.stdin.readline

def segment_init(base):
    nums = list(map(int, input().split()))
    for i in range(base, base + len(nums)):
        segment[i] = nums[i - base]

    for i in range(base - 1, 0, -1):
        segment[i] = min(segment[i * 2], segment[i * 2 + 1])

def segment_update(start_index, change):
    segment[start_index] = change
    start_index //= 2
    while start_index >= 1:
        segment[start_index] = min(segment[start_index * 2], segment[start_index * 2 + 1])
        start_index //= 2

def segment_partial_min(start_index, end_index):
    answer = 10 ** 9 + 1
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

N = int(input())
base = 1

while base < N:
    base <<= 1

segment = [10 ** 9 + 1 for _ in range(base * 2)]

segment_init(base)

M = int(input())

for _ in range(M):
    nums = list(map(int, input().split()))
    if nums[0] == 1:
        start_index, change = nums[1] + base - 1, nums[2]
        segment_update(start_index, change)
    else:
        start_index, end_index = nums[1] + base - 1, nums[2] + base - 1
        print(segment_partial_min(start_index, end_index))