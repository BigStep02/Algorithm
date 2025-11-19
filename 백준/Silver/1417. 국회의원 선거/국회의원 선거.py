import sys
import heapq

def solve(v1, hq):
  cnt = 0

  while hq:
    A = -heapq.heappop(hq)

    if v1 > A:
      return cnt
    
    heapq.heappush(hq, -(A - 1))
    v1 += 1
    cnt += 1

def input():
  input = sys.stdin.readline;

  N = int(input())

  people = [int(input()) for i in range(N)]
  if N == 1:
    return 0

  v1 = people[0]

  hq = []
  for i in range(1, N):
    heapq.heappush(hq, -people[i])

  return solve(v1, hq)

print(input())