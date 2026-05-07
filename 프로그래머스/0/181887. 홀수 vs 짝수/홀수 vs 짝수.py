def solution(nums):
    홀수 = 0
    짝수 = 0

    #1번
    for i in range(len(nums)):
        if(i + 1) % 2 == 0:
            짝수 += nums[i]
        else :
            홀수 += nums[i]
    return max(짝수, 홀수)