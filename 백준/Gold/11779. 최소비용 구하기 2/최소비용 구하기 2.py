import sys, heapq
input = sys.stdin.readline

def daik(visited):
    while len(queue):
        c, node = heapq.heappop(queue)
        if visited[node] < c:
            continue
        for next_node, cost, in graph[node]:
            if visited[next_node] <= visited[node] + cost: continue
            visited[next_node] = visited[node] + cost
            path[next_node] = node
            heapq.heappush(queue, [visited[next_node], next_node])
            

N = int(input())
M = int(input())
graph = [[] for _ in range(N + 1)]
visited = [1e9 for _ in range(N + 1)]

for _ in range(M):
    a, b, c = map(int, input().split())
    graph[a].append([b, c])
start, end = map(int, input().split())

path = [0 for _ in range(N + 1)]
queue = []
visited[start] = 0
heapq.heappush(queue, [0, start])
daik(visited)

print(visited[end])
cur = end
answer = []
while cur != start:
    answer.append(cur)
    cur = path[cur]

answer.append(start)
print(len(answer))
print(*answer[::-1])