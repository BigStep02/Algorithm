import sys
input = sys.stdin.readline

def binary_search(target):
    left, right = 0, len(first_nums) - 1
    while left <= right:
        mid = (left + right) // 2
        if first_nums[mid] == target: return True
        elif first_nums[mid] < target:
            left = mid + 1
        else: right = mid - 1
    
    return False

N = int(input())
first_nums = sorted(list(map(int, input().split())))
M = int(input())
second_nums = list(map(int, input().split()))

for x in second_nums:
    if binary_search(x): print(1)
    else: print(0)