def solution(N, K):
    nums = []
    
    for i in range(K, N + 1):
        if i % K == 0:
            nums.append(i)
    
    return nums