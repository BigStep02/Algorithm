#include <bits/stdc++.h>

using namespace std;

struct Node{
  int x;
  int y;
};

int N;
vector<vector<int>> board;
vector<vector<int>> visited;
Node dir[2] = {{1, 0}, {0, 1}};
queue<Node> q;

void BFS(){
  while(!q.empty()){
    auto [x, y] = q.front();
    q.pop();
    if(x == N - 1 and y == N - 1){
      cout << "HaruHaru";
      exit(0);
    }
    for(int i = 0; i < 2; i++){
      int nx = x + dir[i].x * board[x][y];
      int ny = y + dir[i].y * board[x][y];
      if(nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
      if(visited[nx][ny] != -1) continue;
      q.push({nx, ny});
      visited[nx][ny] = 1;
    }
  }
}

int main(){
  cin >> N;
  board.resize(N, vector<int>(N, 0));
  visited.resize(N, vector<int>(N, -1));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> board[i][j];
    }
  }

  visited[0][0] = 1;
  q.push({0, 0});

  BFS();

  cout << "Hing";
}