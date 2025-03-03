def solution(wallpaper):
    index = []
    for i in range(len(wallpaper)):
        for j in range(len(wallpaper[i])):
            if wallpaper[i][j] == '#':
                index.append((i, j))
    
    index.sort(key = lambda x : x[0])
    x1, x2 = index[0][0], index[-1][0]
    index.sort(key = lambda x : x[1])
    y1, y2 = index[0][1], index[-1][1]
            
    return x1, y1, x2 + 1, y2 + 1