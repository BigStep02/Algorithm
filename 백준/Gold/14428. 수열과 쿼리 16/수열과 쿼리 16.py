import sys
input = sys.stdin.readline

def segment_init(base):
    nums = list(map(int, input().split()))
    for i in range(base, base + N):
        segment[i][0] = nums[i - base]
        segment[i][1] = i

    for i in range(base - 1, 0, -1):
        if segment[i * 2][0] < segment[i * 2 + 1][0]:
            segment[i] = [segment[i * 2][0], segment[i * 2][1]]
        elif segment[i * 2][0] > segment[i * 2 + 1][0]:
            segment[i] = [segment[i * 2 + 1][0], segment[i * 2 + 1][1]]
        else:
            segment[i] = [segment[i * 2][0], min(segment[i * 2][1], segment[i * 2 + 1][1])]

def segment_update(start_index, value):
    segment[start_index] = [value, start_index]
    while start_index > 1:
        start_index //= 2
        if segment[start_index * 2][0] < segment[start_index * 2 + 1][0]:
            segment[start_index] = [segment[start_index * 2][0], segment[start_index * 2][1]]
        elif segment[start_index * 2][0] > segment[start_index * 2 + 1][0]:
            segment[start_index] = [segment[start_index * 2 + 1][0], segment[start_index * 2 + 1][1]]
        else:
            segment[start_index] = [segment[start_index * 2][0], min(segment[start_index * 2][1], segment[start_index * 2 + 1][1])]

def segment_partial_min(start_index, end_index):
    global answer, answer_index
    
    while start_index <= end_index:
        if start_index % 2 == 1:
            if answer > segment[start_index][0]:
                answer = segment[start_index][0]
                answer_index = segment[start_index][1]
            elif answer == segment[start_index][0]:
                answer_index = min(answer_index, segment[start_index][1])
            start_index += 1
        if end_index % 2 == 0:
            if answer > segment[end_index][0]:
                answer = segment[end_index][0]
                answer_index = segment[end_index][1]
            elif answer == segment[end_index][0]:
                answer_index = min(answer_index, segment[end_index][1])
            end_index -= 1
        start_index //= 2
        end_index //= 2

N = int(input())
base = 1
while base < N:
    base <<= 1

segment = [[10 ** 9 + 1, 0] for i in range(base * 2)]

segment_init(base)
M = int(input())
for _ in range(M):
    a, b, c = map(int, input().split())
    if a == 1:
        start_index = b + base - 1
        segment_update(start_index, c)
    else:
        start_index, end_index = b + base - 1, c + base - 1
        answer = 10 ** 10
        answer_index = -1
        segment_partial_min(start_index, end_index)
        print(answer_index - base + 1)