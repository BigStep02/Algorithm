from itertools import combinations
import sys
input = sys.stdin.readline

def check_distance(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)

def check():
    min_distance = 10 ** 10
    for select_chicken in chickens:
        temp = 0
        for house in houses:
            house_distance = 10 ** 10
            for chicken in select_chicken:
                house_distance = min(house_distance, check_distance(chicken[0], chicken[1], house[0], house[1]))
            temp += house_distance
        min_distance = min(min_distance, temp)

    return min_distance

N, M = map(int, input().split())
board = [[0 for _ in range(N)] for _ in range(N)]
houses = []
chickens = []


for i in range(N):
    nums = list(map(int, input().split()))
    for j in range(len(nums)):
        if nums[j] == 1:
            houses.append([i, j])
            board[i][j] = 1
        if nums[j] == 2:
            chickens.append([i, j])
            board[i][j] = 2

chickens = list(combinations(chickens, M))

print(check())