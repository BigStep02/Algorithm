#include <bits/stdc++.h>

using namespace std;

struct Node{
  int x;
  int y;
};

int N, M, myX, myY;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
vector<vector<int>> board;
vector<vector<int>> visited;
queue<Node> q;

void BFS(){
  while(!q.empty()){
    auto [x, y] = q.front();
    q.pop();
    for(int i = 0; i < 8; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
      if(visited[nx][ny] != -1) continue;
      visited[nx][ny] = visited[x][y] + 1;
      q.push({nx, ny});
    }
  }
}

int main(){
  cin >> N >> M;

  board.resize(N, vector<int>(N, 0));
  visited.resize(N, vector<int>(N, -1));

  cin >> myX >> myY;

  visited[myX - 1][myY - 1] = 0;
  q.push({myX - 1, myY - 1});

  BFS();

  for(int i = 0; i < M; i++){
    int a, b; cin >> a >> b;
    cout << visited[a - 1][b - 1] << " ";
  }
}