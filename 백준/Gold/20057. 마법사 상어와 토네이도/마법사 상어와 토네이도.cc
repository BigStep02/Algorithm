#include <bits/stdc++.h>

using namespace std;

int N, x, y, ans = 0;
int dir = 0;
int step = 1;
bool flag = true;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int tornado[9] = {2, 10, 7, 1, 5, 10, 7, 1, 2};
int xIdx[4][10] = {
  {-2, -1, -1, -1, 0, 1, 1, 1, 2, 0},
  {0, 1, 0, -1, 2, 1, 0, -1, 0, 1},
  {2, 1, 1, 1, 0, -1, -1, -1, -2, 0},
  {0, -1, 0, 1, -2, -1, 0, 1, 0, -1}
};
int yIdx[4][10] = {
  {0, -1, 0, 1, -2, -1, 0, 1, 0, -1},
  {-2, -1, -1, -1, 0, 1, 1, 1, 2, 0},
  {0, 1, 0, -1, 2, 1, 0, -1, 0, 1},
  {2, 1, 1, 1, 0, -1, -1, -1, -2, 0}
};
vector<vector<int>> board;

void spread(){
  int totalSpread = 0;

  for(int i = 0; i < 9; i++){
    int nx = x + xIdx[dir][i];
    int ny = y + yIdx[dir][i];
    int out = (board[x][y] * tornado[i]) / 100;
    if(nx < 0 or nx >= N or ny < 0 or ny >= N) ans += out;
    else board[nx][ny] += out;

    totalSpread += out;
  }

  int nx = x + xIdx[dir][9];
  int ny = y + yIdx[dir][9];
  if(nx < 0 or nx >= N or ny < 0 or ny >= N) ans += board[x][y] - totalSpread;
  else board[nx][ny] += board[x][y] - totalSpread;

  board[x][y] = 0;
}

int main(){
  cin >> N;
  x = N / 2, y = N / 2;
  board.resize(N, vector<int>(N, 0));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> board[i][j];
    }
  }

  while(true){
    for(int i = 0; i < step; i++){
      x = x + dx[dir];
      y = y + dy[dir];
      if(x < 0 or x >= N or y < 0 or y >= N) break;
      spread();
      if(x == 0 and y == 0) break;
    }
    if(x == 0 and y == 0) break;

    dir = (dir + 1) % 4;

    if(!flag){
      step++;
    }
    flag = !flag;
  }

  cout << ans;
}