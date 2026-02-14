#include <bits/stdc++.h>

using namespace std;

struct Node{
  int x;
  int y;
};

int N, M;
vector<vector<char>> board;
vector<vector<int>> visited;
queue<Node> q;

void bfs(){
  while(!q.empty()){
    auto [x, y] = q.front();
    q.pop();
    int nx = x;
    int ny = y + 1;
    if(nx < 0 or nx >= N or ny < 0 or ny >= M) continue;
    if(visited[nx][ny] != -1) continue;
    visited[nx][ny] = visited[x][y] + 1;
    q.push({nx, ny});
  }
}

int main(){
  cin >> N >> M;

  board.resize(N, vector<char>(M));
  visited.resize(N, vector<int>(M, -1));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> board[i][j];
      if(board[i][j] == 'c'){
        q.push({i, j});
        visited[i][j] = 0;
      }
    }
  }
  
  bfs();

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cout << visited[i][j] << " ";
    }
    cout << "\n";
  }
}