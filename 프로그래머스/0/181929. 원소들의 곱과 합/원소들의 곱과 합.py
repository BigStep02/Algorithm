def solution(nums):
    first = 1
    second = 0
    
    for i in nums:
        first *= i
        
    for i in nums:
        second += i
    second **= 2
    
    if first < second:
        return 1
    else: return 0