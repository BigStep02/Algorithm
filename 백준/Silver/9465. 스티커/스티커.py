import sys
input = sys.stdin.readline

Test_case = int(input())

for _ in range(Test_case):
    N = int(input())
    nums = [list(map(int, input().split())) for _ in range(2)]
    dp = [[0 for _ in range(N + 1)] for _ in range(2)]
    dp[0][1], dp[1][1] = nums[0][0], nums[1][0]
    if N != 1:
        dp[0][2], dp[1][2] = dp[1][1] + nums[0][1], dp[0][1] + nums[1][1]

        for i in range(3, N + 1):
            dp[0][i] = max(dp[1][i - 2], dp[1][i - 1]) + nums[0][i - 1]
            dp[1][i] = max(dp[0][i - 2], dp[0][i - 1]) + nums[1][i - 1]

    print(max(map(max, dp)))