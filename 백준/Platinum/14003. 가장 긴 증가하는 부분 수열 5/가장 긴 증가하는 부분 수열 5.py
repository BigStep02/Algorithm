def binary_search(left, right, num):
    answer = 0

    while left <= right:
        mid = (left + right) // 2
        if lis[mid] > num:
            answer = mid
            right = mid - 1
        elif lis[mid] == num:
            return mid
        else:
            left = mid + 1
    
    return answer

import sys
input = sys.stdin.readline

N = int(input())
nums = list(map(int, input().split()))
lis = []
trace = []
lis.append(nums[0])
trace.append(0)


for i in range(1, len(nums)):
    if lis[-1] >= nums[i]:
        insert_num = binary_search(0, len(lis) - 1, nums[i])
        lis[insert_num] = nums[i]
        trace.append(insert_num)
        continue
    lis.append(nums[i])
    trace.append(len(lis) - 1)

print(len(lis))
idx = len(lis) - 1
answer = []
for i in range(len(trace) - 1, -1, -1):
    if trace[i] == idx:
        answer.append(nums[i])
        idx -= 1
    if idx < 0:
        break

print(*reversed(answer))