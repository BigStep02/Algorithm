#include <bits/stdc++.h>

using namespace std;

struct Node{
  int x;
  int y;
};

int N, M, K;
int dx_even[6] = {-1, -1, 0, 0, 1, 1};
int dy_even[6] = {-1, 0, -1, 1, -1, 0};
int dx_odd[6] = {-1, -1, 0, 0, 1, 1};
int dy_odd[6] = {0, 1, -1, 1, 0, 1};
vector<vector<int>> board;
vector<vector<int>> visited;
queue<Node> q;

void BFS(){
  while(!q.empty()){
    auto [x, y] = q.front();
    q.pop();
    for(int i = 0; i < 6; i++){
      int nx = x + (x % 2 == 0 ? dx_even[i] : dx_odd[i]);
      int ny = y + (x % 2 == 0 ? dy_even[i] : dy_odd[i]);
      if(nx < 0 or nx >= N or ny < 0 or ny >= M) continue;
      if(visited[nx][ny] != -1 or board[nx][ny] == 1) continue;
      visited[nx][ny] = visited[x][y] + 1;
      q.push({nx, ny});
    }
  }
}

int main(){
  cin >> N >> M >> K;

  board.resize(N, vector<int>(M, 0));
  visited.resize(N, vector<int>(M, -1));

  for(int i = 0; i < K; i++){
    int a, b; cin >> a >> b;
    board[a][b] = 1;
  }

  q.push({0, 0});
  visited[0][0] = 0;
  
  BFS();

  cout << visited[N - 1][M - 1];
}