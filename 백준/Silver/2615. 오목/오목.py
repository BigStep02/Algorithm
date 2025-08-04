import sys
input = sys.stdin.readline

board = [list(map(int, input().split())) for _ in range(19)]

direction = [[1, 0], [0, 1], [1, 1], [1, -1]]

coin = [0, 0]

while True:
    if board[coin[0]][coin[1]] != 0:
        for i in range(4):
            nowCoin = [coin[0], coin[1]]
            count = 1
            for _ in range(4):
                nx, ny = nowCoin[0] + direction[i][0], nowCoin[1] + direction[i][1]
                if nx < 0 or nx >= 19 or ny < 0 or ny >= 19: break
                if board[coin[0]][coin[1]] == board[nx][ny]:
                    count += 1
                    nowCoin = [nx, ny]
            
            if count == 5:
                px = coin[0] - direction[i][0]
                py = coin[1] - direction[i][1]
                if px >= 0 and px < 19 and py >= 0 and py < 19 and board[px][py] == board[coin[0]][coin[1]]: continue

                nx = nowCoin[0] + direction[i][0]
                ny = nowCoin[1] + direction[i][1]
                if nx >= 0 and nx < 19 and ny >= 0 and ny < 19 and board[nx][ny] == board[coin[0]][coin[1]]: continue

                if i != 3:
                    print(board[coin[0]][coin[1]])
                    print(coin[0] + 1, coin[1] + 1)
                    sys.exit()
                else:
                    print(board[coin[0]][coin[1]])
                    print(coin[0] + 5, coin[1] - 3)
                    sys.exit()
    
    coin[1] += 1
    if coin[1] == 19:
        coin[0] += 1
        coin[1] = 0
        if coin[0] == 19:
            break

print(0)