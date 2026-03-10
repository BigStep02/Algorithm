#include <bits/stdc++.h>

using namespace std;

int N, M, R;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int>> board;
vector<int> tempBoard;

int main(){
  cin >> N >> M >> R;

  board.resize(N, vector<int>(M, 0));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> board[i][j];
    }
  }

  for(int i = 0; i < min(N, M) / 2; i++){
    int x = i, y = i;
    int dir = 0;
    tempBoard.clear();
    while(dir <= 3){
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(nx < i or nx >= N - i or ny < i or ny >= M - i){
        dir++;
        continue;
      } 
      tempBoard.push_back(board[nx][ny]);
      x = nx;
      y = ny;
    }

    int rot = R % tempBoard.size();

    rotate(tempBoard.rbegin(), tempBoard.rbegin() + rot, tempBoard.rend());

    x = i, y = i, dir = 0;
    int idx = 0;
    while(dir <= 3){
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(nx < i or nx >= N - i or ny < i or ny >= M - i){
        dir++;
        continue;
      }
      board[nx][ny] = tempBoard[idx];
      x = nx;
      y = ny;
      idx++;
    }
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cout << board[i][j] << " ";
    }
    cout << "\n";
  }
}