#include <bits/stdc++.h>

using namespace std;

struct Node{
  int x;
  int y;
};

int N, M, T;
vector<vector<int>> board;
vector<int> cleaners;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void spread(){
  vector<vector<int>> exboard(N, vector<int>(M, 0));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(board[i][j] == -1) exboard[i][j] = -1;
      else if (board[i][j] > 0){
        int spreadSize = board[i][j] / 5;
        int cnt = 0;
        for(int next = 0; next < 4; next++){
          int nx = i + dx[next];
          int ny = j + dy[next];
          if(nx < 0 or nx >= N or ny < 0 or ny >= M) continue;
          if(board[nx][ny] == -1) continue;
          exboard[nx][ny] += spreadSize;
          cnt++; 
        }
        exboard[i][j] += board[i][j] - spreadSize * cnt;
      }
    }
  }

  board = exboard;
}

void clean(){
  int up = cleaners[0];
  int down = cleaners[1];
  //윗 쪽 공기청정기
  for(int i = up - 1; i > 0; i--) board[i][0] = board[i - 1][0];
  for(int i = 0; i < M - 1; i++) board[0][i] = board[0][i + 1];
  for(int i = 0; i < up; i++) board[i][M - 1] = board[i + 1][M - 1];
  for(int i = M - 1; i > 1; i--) board[up][i] = board[up][i - 1];
  board[up][1] = 0;
  //아랫 쪽 공기청정기
  for(int i = down + 1; i < N - 1; i++) board[i][0] = board[i + 1][0];
  for(int i = 0; i < M - 1; i++) board[N - 1][i] = board[N - 1][i + 1];
  for(int i = N - 1; i > down; i--) board[i][M - 1] = board[i - 1][M - 1];
  for(int i = M - 1; i > 1; i--) board[down][i] = board[down][i - 1];
  board[down][1] = 0;
}

int main(){
  cin >> N >> M >> T;

  board.resize(N, vector<int>(M));
  
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> board[i][j];
      if(board[i][j] == -1) cleaners.push_back(i);
    }
  }

  for(int i = 0; i < T; i++){
    spread();
    clean();
  }

  int ans = 0;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(board[i][j] == -1) continue;
      ans += board[i][j];
    }
  }

  cout << ans;
}