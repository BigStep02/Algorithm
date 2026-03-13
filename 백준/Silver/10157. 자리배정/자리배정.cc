#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> board;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
  cin >> N >> M;

  board.resize(N, vector<int>(M, 0));

  int total = N * M;
  int cnt = 1;
  int dir = 0;
  int x = 0;
  int y = 0;
  board[x][y] = cnt++;

  while(cnt <= total){
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx < 0 or nx >= N or ny < 0 or ny >= M or board[nx][ny] != 0){
      dir = (dir + 1) % 4;
      continue;
    }
    board[nx][ny] = cnt++;
    x = nx;
    y = ny;
  }

  int ansX = -1, ansY = -1;
  int K; cin >> K;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(board[i][j] == K){
        ansX = i + 1;
        ansY = j + 1;
      }
    }
  }

  if(ansX == -1) cout << 0;
  else cout << ansX << " " << ansY;
}