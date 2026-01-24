#include <bits/stdc++.h>

using namespace std;

struct Point{
  int x;
  int y;
  int nowColor;
};

int N, M, jumpPower;
vector<vector<int>> board;
vector<vector<int>> visited;
queue<Point> q;

void BFS(){
  while(!q.empty()){
    auto [x, y, nowColor] = q.front();
    q.pop();
    if(x == N - 1 and y == M - 1){
      cout << "ALIVE";
      exit(0);
    }
    for(int dx = -jumpPower; dx <= jumpPower; dx++){
      for(int dy = -jumpPower; dy <= jumpPower; dy++){
        if(abs(dx) + abs(dy) <= jumpPower){
          int nx = x + dx;
          int ny = y + dy;
          if(nx < 0 or nx >= N or ny < 0 or ny >= M) continue;
          if(board[nx][ny] != nowColor or visited[nx][ny] != -1) continue;
          visited[nx][ny] = 1;
          q.push({nx, ny, board[nx][ny]});
        }
      }
    }
  }
}

int main(){
  cin >> N >> M;
  board.resize(N, vector<int>(M, 0));
  visited.resize(N, vector<int>(M, -1));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> board[i][j];
    }
  }

  cin >> jumpPower;

  visited[0][0] = 1;
  q.push({0, 0, board[0][0]});

  BFS();

  cout << "DEAD";
}