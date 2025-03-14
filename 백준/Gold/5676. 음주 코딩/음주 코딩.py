import sys
input = sys.stdin.readline

def segment_init(base):
    nums = list(map(int, input().split()))
    for i in range(base, base + len(nums)):
        if nums[i - base] < 0:
            segment[i] = -1
        elif nums[i - base] > 0:
            segment[i] = 1
        else: segment[i] = 0
    
    for i in range(base - 1, 0, -1):
        segment[i] = segment[i * 2] * segment[i * 2 + 1]

def segment_update(start_index, change):
    if change < 0:
        segment[start_index] = -1
    elif change > 0:
        segment[start_index] = 1
    else: segment[start_index] = 0
    start_index //= 2
    
    while start_index >= 1:
        segment[start_index] = segment[start_index * 2] * segment[start_index * 2 + 1]
        start_index //= 2

def segment_partial_product(start_index, end_index):
    partial_product = 1
    while start_index <= end_index:
        if start_index % 2 == 1:
            if segment[start_index] == 0:
                return 0
            partial_product *= segment[start_index]
            start_index += 1
        if end_index % 2 == 0:
            if segment[end_index] == 0:
                return 0
            partial_product *= segment[end_index]
            end_index -= 1
        start_index //= 2
        end_index //= 2

    return partial_product

while True:
    try:
        N, M = map(int, input().split())
        base = 1
        
        while base < N:
            base <<= 1
        
        segment = [1] * (base * 2)

        segment_init(base)

        for _ in range(M):
            nums = list(input().split())
            nums[1], nums[2] = int(nums[1]), int(nums[2])
            if nums[0] == 'C':
                start_index = nums[1] + base - 1
                segment_update(start_index, nums[2])
            else:
                partial_product = 0
                start_index, end_index = nums[1] + base - 1, nums[2] + base - 1
                partial_product = segment_partial_product(start_index, end_index)
                if partial_product < 0: print('-', end = "")
                elif partial_product > 0: print("+", end = "")
                else: print("0", end = "")
        print()

    except Exception:
        break