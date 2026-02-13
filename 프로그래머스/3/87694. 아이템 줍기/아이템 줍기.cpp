#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int bfs(vector<vector<int>> &board, queue<pair<int, int>> &q, vector<vector<int>> &visited, int itemX, int itemY){
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        if(x == itemX and y == itemY){
            return (visited[x][y] - 1) / 2;
        }
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 or nx >= 102 or ny < 0 or ny >= 102) continue;
            if(board[nx][ny] != 1 or visited[nx][ny] != 0) continue;
            visited[nx][ny] = visited[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int row = rectangle.size();
    int col = rectangle[0].size();
    
    vector<vector<int>> board(102, vector<int>(102, 0));
    vector<vector<int>> visited(102, vector<int>(102, 0));
    
    for(const auto &rect : rectangle){
        int x1 = rect[0] * 2;
        int y1 = rect[1] * 2;
        int x2 = rect[2] * 2;
        int y2 = rect[3] * 2;
        for(int x = x1; x <= x2; x++){
            for(int y = y1; y <= y2; y++){
                if(x > x1 && x < x2 && y > y1 && y < y2){
                    board[x][y] = 2;
                } else if(board[x][y] != 2) {
                    board[x][y] = 1;
                }
            }
        }
    }
    
    queue<pair<int, int>> q;
    q.push({characterX * 2, characterY * 2});
    visited[characterX * 2][characterY * 2] = 1;
    
    return bfs(board, q, visited, itemX * 2, itemY * 2);
}