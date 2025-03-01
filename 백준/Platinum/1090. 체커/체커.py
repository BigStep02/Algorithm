n = int(input())
answer = 0
now = []
now_x = []
now_y = []

answer = [-1]*n

for _ in range(n):
    temp1, temp2 = map(int, input().split())
    now.append([temp1, temp2])
    now_x.append(temp1)
    now_y.append(temp2)

for x in now_x:
    for y in now_y:
        dist = []
        for ex, ey in now:
            dist.append(abs(ex - x) + abs(ey - y))
        dist.sort()
    
        temp = 0
        for i in range(len(dist)):
            temp += dist[i]
            if answer[i] == -1:
                answer[i] = temp
            else:
                answer[i] = min(temp, answer[i])

print(*answer)