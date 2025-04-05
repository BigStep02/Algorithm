import heapq
import sys
input = sys.stdin.readline

N = int(input())
queue = []

for _ in range(N):
    nums = list(map(int, input().split()))
    for num in nums:
        heapq.heappush(queue, num)
        if len(queue) > N:
            heapq.heappop(queue)

print(queue[0])