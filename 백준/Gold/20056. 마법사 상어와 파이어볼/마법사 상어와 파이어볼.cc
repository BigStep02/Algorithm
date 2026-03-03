#include <bits/stdc++.h>

using namespace std;

struct fireBall{
  int x, y, size, speed, dir;
};

int N, M, K;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<fireBall> fireBalls;
vector<vector<vector<fireBall>>> board;

void move(){
  for(fireBall &f : fireBalls){
    int nx = (f.x + dx[f.dir] * (f.speed % N) + N) % N;
    int ny = (f.y + dy[f.dir] * (f.speed % N) + N) % N;
    board[nx][ny].push_back({nx, ny, f.size, f.speed, f.dir});
  }
}

void combine(){
  vector<fireBall> tempFB;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(board[i][j].empty()) continue;
      if(board[i][j].size() == 1) tempFB.push_back(board[i][j][0]);
      else{
        int totalSize = 0, totalSpeed = 0;
        bool even = true, odd = true;
        for(auto &f : board[i][j]){
          totalSize += f.size;
          totalSpeed += f.speed;
          if(f.dir % 2 == 0) odd = false;
          else even = false;
        }
        int finalSize = totalSize / 5;
        if(finalSize <= 0) continue;
        int finalSpeed = totalSpeed / board[i][j].size();
        int startdir = (even or odd)? 0 : 1;
        for(int next = 0; next < 4; next++){
          tempFB.push_back({i, j, finalSize, finalSpeed, startdir + next * 2});
        }
      }
    }
  }

  fireBalls = tempFB;
}

int main(){
  cin >> N >> M >> K;
  
  for(int i = 0; i < M; i++){
    int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
    fireBalls.push_back({--a, --b, c, d, e});
  }

  while(K--){
    board.assign(N, vector<vector<fireBall>>(N));
    move();
    combine();
  }

  int sum = 0;

  for(auto &f : fireBalls){
    sum += f.size;
  }

  cout << sum;
}