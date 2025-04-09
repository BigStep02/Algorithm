for _ in range(3):
    N = int(input())
    nums = [int(input()) for _ in range(N)]
    total = 0

    for x in nums:
        total += x
    
    if total < 0:
        print('-')
    elif total > 0:
        print('+')
    else: print(0)