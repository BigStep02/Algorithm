#include <bits/stdc++.h>

using namespace std;

int N, M, dir, ans = 0;
pair<int, int> cleaner;
vector<vector<int>> board;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void clean(){
  if(board[cleaner.first][cleaner.second] == 0){
    ans++;
    board[cleaner.first][cleaner.second] = -1;
  }
}

int main(){
  cin >> N >> M;

  int a, b, c; cin >> a >> b >> c;
  cleaner.first = a;
  cleaner.second = b;
  dir = c;

  board.resize(N, vector<int>(M, 0));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> board[i][j];
    }
  }

  while(true){
    clean();

    bool isEmpty = false;
    for(int i = 0; i < 4; i++){
      int nx = cleaner.first + dx[i];
      int ny = cleaner.second + dy[i];
      if(nx < 0 or nx >= N or ny < 0 or ny >= M) continue;
      if(board[nx][ny] == 0) isEmpty = true;
    }

    if(!isEmpty){
      int bx = cleaner.first - dx[dir];
      int by = cleaner.second - dy[dir];
      if(board[bx][by] == 1) break;
      cleaner.first = bx;
      cleaner.second = by;
    }
    else{
      for(int i = 0; i < 4; i++){
        dir = (dir + 3) % 4;
        int nx = cleaner.first + dx[dir];
        int ny = cleaner.second + dy[dir];
        if(nx < 0 or nx >= N or ny < 0 or ny >= M) continue;
        if(board[nx][ny] == 0){
          board[nx][ny] = -1;
          cleaner.first = nx;
          cleaner.second = ny;
          ans++;
          break;
        }
      }
    }
  }

  cout << ans;
}