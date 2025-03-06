import sys
input = sys.stdin.readline

def check_max(mid):
    cnt = 0
    for i in range(1, len(rest)):
        temp = rest[i] - rest[i - 1] - 1
        cnt += temp // mid
        if cnt > M:
            return False
    return True

def binary_search():
    answer = 1e9
    left, right = 1, L
    while left <= right:
        mid = (left + right) // 2
        if check_max(mid):
            answer = min(answer, mid)
            right = mid - 1
        else:
            left = mid + 1

    return answer

N, M, L = map(int, input().split())
rest = list(map(int, input().split()))
rest.append(0)
rest.append(L)
rest.sort()

print(binary_search())