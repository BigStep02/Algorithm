#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<string> board;
vector<vector<int>> visited;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
  cin >> N >> M;

  board.resize(N);
  visited.resize(N, vector<int>(M, INT_MAX));

  for(int i = 0; i < N; i++){
    cin >> board[i];
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(board[i][j] == 'X'){
        for(int next = 0; next < 4; next++){
          int nx = i + dx[next];
          int ny = j + dy[next];
          if(nx < 0 or nx >= N or ny < 0 or ny >= M){
            if(visited[i][j] == INT_MAX) visited[i][j] = 1;
            else visited[i][j]++;
            continue;
          }
          if(board[nx][ny] == '.'){
            if(visited[i][j] == INT_MAX) visited[i][j] = 1;
            else visited[i][j]++;
          }
        }
      }
    }
  }

  int minX = INT_MAX, minY = INT_MAX, maxX = -1, maxY = -1;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(board[i][j] == 'X' and (visited[i][j] < 3 or visited[i][j] == INT_MAX)){
        minX = min(minX, i);
        minY = min(minY, j);
        maxX = max(maxX, i);
        maxY = max(maxY, j);
      }
    }
  }

  for(int i = minX; i <= maxX; i++){
    for(int j = minY; j <= maxY; j++){
      if(board[i][j] == 'X' and (visited[i][j] == 3 or visited[i][j] == 4)) board[i][j] = '.';
      cout << board[i][j];
    }
    cout << "\n";
  }
}