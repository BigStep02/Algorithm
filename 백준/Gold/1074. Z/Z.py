import sys
input = sys.stdin.readline

def recur(N, r, c, x, y, cnt):
    if N == 0:
        return cnt
    
    size = 2 ** (N - 1)
    if r < x + size and c < y + size:
        return recur(N - 1, r, c, x, y, cnt)
    elif r < x + size and c >= y + size:
        return recur(N - 1, r, c, x, y + size, cnt + size * size)
    elif r >= x + size and c < y + size:
        return recur(N - 1, r, c, x + size, y, cnt + 2 * size * size)
    else:
        return recur(N - 1, r, c, x + size, y + size, cnt + 3 * size * size)
    
N, r, c = map(int, input().split())

print(recur(N, r, c, 0, 0, 0))

