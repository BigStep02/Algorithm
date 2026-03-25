#include <bits/stdc++.h>

using namespace std;

int N, M, rX, rY;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<int> dir;
vector<vector<int>> board;
vector<vector<int>> visited;

void move(){
  int idx = 0;
  int isEnd = 0;
  while(isEnd < 4){
    int nx = rX + dx[dir[idx]];
    int ny = rY + dy[dir[idx]];
    if(nx < 0 or nx >= N or ny < 0 or ny >= M or visited[nx][ny] != 0 or board[nx][ny] == 1){
      isEnd++;
      idx = (idx + 1) % 4;
      continue;
    }
    isEnd = 0;
    visited[nx][ny] = 1;
    rX = nx; rY = ny;
  }
}

int main(){
  cin >> N >> M;

  board.resize(N, vector<int>(M, 0));
  visited.resize(N, vector<int>(M, 0));

  int stop; cin >> stop;

  for(int i = 0; i < stop; i++){
    int a, b; cin >> a >> b;
    board[a][b] = 1;
  }

  cin >> rX >> rY;
  
  dir.resize(4);

  for(int i = 0; i < 4; i++){
    cin >> dir[i];
    dir[i]--;
  }

  visited[rX][rY] = 1;
  move();

  cout << rX << " " << rY;
}