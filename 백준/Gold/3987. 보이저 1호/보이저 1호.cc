#include <bits/stdc++.h>

using namespace std;

int N, M, dirId, maxVal = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char ansDir[4] = {'U', 'R', 'D', 'L'};
vector<string> board;

void change_dir(char now, int &dir){
  if(now == '/'){
    dir ^= 1;
  }
  else{
    dir = 3 - dir;
  }
}

void spread(int x, int y, int dir){
  int cnt = 1, nowDir = dir;

  while(true){
    int nx = x + dx[nowDir];
    int ny = y + dy[nowDir];
    if(nx < 0 or nx >= N or ny < 0 or ny >= M) break;
    if(cnt >= N * M * 2){
      cout << ansDir[dir] << "\n" << "Voyager";
      exit(0);
    }
    if(board[nx][ny] == 'C') break;
    if(board[nx][ny] == '/' or board[nx][ny] == '\\'){
      change_dir(board[nx][ny], nowDir);
    }
    cnt++;
    x = nx; y = ny;
  }

  if(maxVal < cnt){
    maxVal = cnt;
    dirId = dir;
  }
}

int main(){
  cin >> N >> M;

  board.resize(N);

  for(int i = 0; i < N; i++){
    cin >> board[i];
  }

  int tamsaX, tamsaY;
  cin >> tamsaX >> tamsaY;
  tamsaX--; tamsaY--;

  for(int i = 0; i < 4; i++){
    spread(tamsaX, tamsaY, i);
  }

  cout << ansDir[dirId] << "\n" << maxVal;
}