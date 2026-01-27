#include <bits/stdc++.h>

using namespace std;

struct Node{
  int x;
  int y;
};

int R, C, N;
vector<vector<int>> board;
vector<vector<int>> visited;
queue<Node> q;
vector<int> dx;
vector<int> dy;

void BFS(){
  while(!q.empty()){
    auto [x, y] = q.front();
    q.pop();
    if(x == R - 1){
      cout << visited[x][y];
      exit(0);
    }
    for(int i = 0; i < N; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 0 or nx >= R or ny < 0 or ny >= C) continue;
      if(board[nx][ny] == 0 or visited[nx][ny] != -1) continue;
      visited[nx][ny] = visited[x][y] + 1;
      q.push({nx, ny});
    }
  }
}

int main(){
  cin >> R >> C;

  board.resize(R, vector<int>(C));
  visited.resize(R, vector<int>(C, -1));

  for(int i = 0; i < R; i++){
    for(int j = 0; j < C; j++){
      cin >> board[i][j];
      if(i == 0 and board[0][j] == 1){
        q.push({0, j});
        visited[0][j] = 0;
      }
    }
  }

  cin >> N;
  
  for(int i = 0; i < N; i++){
    int a, b; cin >> a >> b;
    dx.push_back(a);
    dy.push_back(b);  
  }

  BFS();

  cout << -1;
}