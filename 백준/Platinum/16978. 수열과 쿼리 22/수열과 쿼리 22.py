import sys
input = sys.stdin.readline

def segment_init(base, N):
    nums = list(map(int, input().split()))
    for i in range(base, base + N):
        segment[i] = nums[i - base]

    for i in range(base - 1, 0, -1):
        segment[i] = segment[i * 2] + segment[i * 2 + 1]

def segment_update(start_index, change):
    segment[start_index] = change
    start_index //= 2

    while start_index > 0:
        segment[start_index] = segment[start_index * 2] + segment[start_index * 2 + 1]
        start_index //= 2

def segment_check(start_index, end_index):
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

N = int(input())
base = 1

while base < N:
    base <<= 1

segment = [0 for _ in range(base * 2)]

segment_init(base, N)

M = int(input())

firstQuery = []
secondQuery = []
cnt = 1

for _ in range(M):
    nums = list(map(int, input().split()))
    if nums[0] == 1:
        firstQuery.append(nums)
    else:
        secondQuery.append(nums + [cnt])
        cnt += 1

firstQuery.reverse()
secondQuery.sort(key = lambda x : -x[1])
cnt = 0
answer = []

while len(secondQuery):
    nums1 = secondQuery.pop()
    while cnt < nums1[1]:
        if len(firstQuery):
            nums2 = firstQuery.pop()
            segment_update(nums2[1] + base - 1, nums2[2])
            cnt += 1
    result = segment_check(nums1[2] + base - 1, nums1[3] + base - 1)
    answer.append([result, nums1[4]])

answer.sort(key = lambda x : x[1])
for i, j in answer:
    print(i)