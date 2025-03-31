N = int(input())

tile = [list(map(int, input().split())) for _ in range(N)]
dp = [[-1 for _ in range(3)] for _ in range(N)]

dp[0][0] = tile[0][0]
dp[0][1] = tile[0][1]
dp[0][2] = tile[0][2]

for x in range(1, N):
    dp[x][0] = min(dp[x - 1][1] + tile[x][0], dp[x - 1][2] + tile[x][0])
    dp[x][1] = min(dp[x - 1][0] + tile[x][1], dp[x - 1][2] + tile[x][1])
    dp[x][2] = min(dp[x - 1][0] + tile[x][2], dp[x - 1][1] + tile[x][2])

print(min(dp[N - 1]))