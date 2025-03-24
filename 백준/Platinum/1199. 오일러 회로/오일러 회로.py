import sys
input = sys.stdin.readline

def Euler_circuit(graph, now):
    stack = []
    stack.append(now)
    path = []
    while stack:
        now = stack[-1]
        if graph[now]:
            for next_node, cnt in graph[now].items():
                graph[next_node][now] -= 1
                graph[now][next_node] -= 1
                if graph[now][next_node] == 0:
                    graph[now].pop(next_node)
                    graph[next_node].pop(now)
                stack.append(next_node)
                break
        else:
            path.append(now + 1)
            stack.pop()
    
    return path

N = int(input())
nums = [list(map(int, input().split())) for _ in range(N)]
graph = [dict() for _ in range(N)]

for i in range(N):
    deg = 0
    for j in range(N):
        deg += nums[i][j]
        if nums[i][j]:
            graph[i][j] = nums[i][j]
    if deg % 2 != 0:
        print(-1)
        sys.exit()

print(*Euler_circuit(graph, 0))