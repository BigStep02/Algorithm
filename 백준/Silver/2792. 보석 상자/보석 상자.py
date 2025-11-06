import sys
input = sys.stdin.readline

def check(mid):
    global N, M, jewel

    cnt = 0
    for x in jewel:
        cnt += x // mid
        if x % mid > 0:
            cnt += 1

    if cnt > N:
        return False
    return True
    

def binary_search():
    global N, M, jewel

    answer = 0
    start, end = 1, max(jewel)

    while start <= end:
        mid = (start + end) // 2

        if check(mid):
            answer = mid
            end = mid - 1
        else:
            start = mid + 1

    return answer


N, M = map(int, input().split())
jewel = [int(input()) for _ in range(M)]

print(binary_search())