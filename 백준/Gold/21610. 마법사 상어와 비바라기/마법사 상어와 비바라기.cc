#include <bits/stdc++.h>

using namespace std;

struct Node{
  int num;
  bool isDel = false;
};

struct cloude{
  int x, y;
};

int N, M;
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<vector<Node>> board;
vector<pair<int, int>> waterPlus;
queue<cloude> cloudes;

void move(int dir, int speed){
  while(!cloudes.empty()){
    auto [x, y] = cloudes.front();
    cloudes.pop();
    int moveX = (dx[dir] * speed) % N;
    int nx = (x + moveX + N) % N;
    int moveY = (dy[dir] * speed) % N;
    int ny = (y + moveY + N) % N;
    board[nx][ny].num++;
    board[nx][ny].isDel = true;
    waterPlus.push_back({nx, ny});
  }
}

void waterCopy(){
  vector<vector<Node>> tempBoard = board;

  for(auto &p : waterPlus){
    int cnt = 0;
    for(int next = 1; next < 8; next += 2){
      int nx = p.first + dx[next];
      int ny = p.second + dy[next];
      if(nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
      if(board[nx][ny].num <= 0) continue;
      cnt++;
    }
    tempBoard[p.first][p.second].num += cnt;
  }

  board = tempBoard;
}

void makeCloude(){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(board[i][j].num >= 2 and !board[i][j].isDel){
        board[i][j].num -= 2;
        cloudes.push({i, j});
      }
      board[i][j].isDel = false;
    }
  }
}

int main(){
  cin >> N >> M;

  board.resize(N, vector<Node>(N, {0, false}));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> board[i][j].num;
    }
  }

  cloudes.push({N - 1, 0});
  cloudes.push({N - 1, 1});
  cloudes.push({N - 2, 0});
  cloudes.push({N - 2, 1});

  while(M--){
    int dir, speed; cin >> dir >> speed;
    waterPlus.clear();
    move(--dir, speed);
    waterCopy();
    makeCloude();
  }

  int ans = 0;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(board[i][j].num > 0) ans += board[i][j].num;
    }
  }

  cout << ans;
}