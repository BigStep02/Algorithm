def solution(wallpaper):
    answer = []
    index = []
    for i in range(len(wallpaper)):
        for j in range(len(wallpaper[i])):
            if wallpaper[i][j] == '#':
                index.append((i, j))
    
    index.sort(key = lambda x : x[0])
    x1, x2 = index[0][0], index[-1][0]
    index.sort(key = lambda x : x[1])
    y1, y2 = index[0][1], index[-1][1]
    
    answer.append(x1)
    answer.append(y1)
    answer.append(x2 + 1)
    answer.append(y2 + 1)
            
    return answer