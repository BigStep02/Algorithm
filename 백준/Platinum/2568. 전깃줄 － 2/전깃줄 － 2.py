def binary_search(idx):
    left, right = 0, len(Lis) - 1
    answer = 0
    while left <= right:
        mid = (left + right) // 2
        if Lis[mid] > nums[idx][1]:
            answer = mid
            right = mid - 1
        elif Lis[mid] == nums[idx][1]:
            return mid
        else:
            left = mid + 1
        
    return answer

N = int(input())
nums = []
Lis = []
index = []

for _ in range(N):
    a, b = map(int, input().split())
    nums.append([a, b])

nums.sort()
Lis.append(nums[0][1])
index.append(0)

for i in range(1, N):
    if nums[i][1] <= Lis[-1]:
        idx = binary_search(i)
        Lis[idx] = nums[i][1]
        index.append(idx)
    else:
        Lis.append(nums[i][1])
        index.append(len(Lis) - 1)

index_cnt = len(Lis) - 1
answer = []
for i in range(len(index) - 1, -1, -1):
    if index_cnt == index[i]:
        index_cnt -= 1
        continue
    answer.append(nums[i][0])

print(N - len(Lis))
for i in range(len(answer) - 1, -1, -1):
    print(answer[i])