import sys
sys.stdin.readline

N = int(input())
dp = [0 for _ in range(N + 1)]
path = [0 for _ in range(N + 1)]
dp[1] = 0

for i in range(2, N + 1):
    dp[i] = dp[i - 1] + 1
    path[i] = i - 1
    if i % 2 == 0 and dp[i] > dp[i // 2] + 1:
        dp[i] = dp[i // 2] + 1
        path[i] = i // 2
    if i % 3 == 0 and dp[i] > dp[i // 3] + 1:
        dp[i] = dp[i // 3] + 1
        path[i] = i // 3
    
print(dp[N])
count = N
while count != 0:
    print(count, end = " ")
    count = path[count]