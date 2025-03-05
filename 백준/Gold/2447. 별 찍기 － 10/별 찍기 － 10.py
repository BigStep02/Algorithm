def recur(row, col, size):
    global N

    if size == 1:
        return

    for i in range(row + size // 3, row + (size // 3) * 2):
        for j in range(col + size // 3, col + (size // 3) * 2):
            star[i][j] = ' '
        
    for i in range(3):
        for j in range(3):
            recur(row + i * size // 3, col + j * size // 3, size // 3)

N = int(input())
star = [['*' for _ in range(N)] for _ in range(N)]

recur(0, 0, N)

for i in range(N):
    for j in range(N):
        print(star[i][j], end = "")
    print()