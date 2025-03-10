import sys
input = sys.stdin.readline

def segment_init(base):
    nums = list(map(int, input().split()))
    for i in range(base, base + N):
        segment[i][0] = nums[i - base]
        segment[i][1] = i
    
    for i in range(base - 1, 0, -1):
        if segment[i * 2][0] < segment[i * 2 + 1][0]:
            segment[i][0], segment[i][1] = segment[i * 2][0], segment[i * 2][1]
        elif segment[i * 2][0] == segment[i * 2 + 1][0]:
            segment[i][0], segment[i][1] = segment[i * 2][0], min(segment[i * 2][1], segment[i * 2 + 1][1])
        else:
            segment[i][0], segment[i][1] = segment[i * 2 + 1][0], segment[i * 2 + 1][1]            

def segment_update(start_index, change):
    segment[start_index][0] = change
    start_index //= 2
    while start_index > 0:
        if segment[start_index * 2][0] < segment[start_index * 2 + 1][0]:
            segment[start_index][0], segment[start_index][1] = segment[start_index * 2][0], segment[start_index * 2][1]
        elif segment[start_index * 2][0] == segment[start_index * 2 + 1][0]:
            segment[start_index][0], segment[start_index][1] = segment[start_index * 2][0], min(segment[start_index * 2][1], segment[start_index * 2 + 1][1])
        else:
            segment[start_index][0], segment[start_index][1] = segment[start_index * 2 + 1][0], segment[start_index * 2 + 1][1]
        start_index //= 2

def segment_partial_min(start_index, end_index):
    answer = 10 ** 10
    answer_index = 10 ** 10
    while start_index <= end_index:
        if start_index % 2 == 1:
            if segment[start_index][0] < answer:
                answer = segment[start_index][0]
                answer_index = segment[start_index][1]
            elif segment[start_index][0] == answer:
                answer_index = min(answer_index, segment[start_index][1])
            start_index += 1
        if end_index % 2 == 0:
            if segment[end_index][0] < answer:
                answer = segment[end_index][0]
                answer_index = segment[end_index][1]
            elif segment[end_index][0] == answer:
                answer_index = min(answer_index, segment[end_index][1])
            end_index -= 1
        start_index //= 2
        end_index //= 2

    return answer_index - base + 1

N = int(input())
base = 1
while base < N:
    base <<= 1

segment = [[10 ** 10, 0]for _ in range(base * 2)]

segment_init(base)
M = int(input())
for _ in range(M):
    nums = list(map(int, input().split()))
    if nums[0] == 1:
        start_index = nums[1] + base - 1
        segment_update(start_index, nums[2])
    else:
        start_index = base
        end_index = base + N - 1
        print(segment_partial_min(start_index, end_index))