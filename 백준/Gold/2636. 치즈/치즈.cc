#include <bits/stdc++.h>

using namespace std;

struct Node{
  int x, y;
};

int N, M;
vector<vector<int>> board;
vector<vector<int>> visited;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(){
  visited.assign(N, vector<int>(M, 0));
  queue<Node> q;
  q.push({0, 0});
  visited[0][0] = -1;

  while(!q.empty()){
    auto [x, y] = q.front();
    q.pop();
    for(int next = 0; next < 4; next++){
      int nx = x + dx[next];
      int ny = y + dy[next];
      if(nx < 0 or nx >= N or ny < 0 or ny >= M) continue;
      if(visited[nx][ny] != 0) continue;
      if(board[nx][ny] == 1){
        visited[nx][ny] = 1;
        continue;
      }
      q.push({nx, ny});
      visited[nx][ny] = -1;
    }
  }
}

int erase(){
  int cnt = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(visited[i][j] == 1){
        cnt++;
        board[i][j] = 0;
      }
    }
  }

  return cnt;
}

int main(){
  cin >> N >> M;

  board.resize(N, vector<int>(M, 0));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> board[i][j];
    }
  }

  int ans = 0, timer = 0;

  while(true){
    BFS();
    int cnt = erase();
    if(cnt != 0) ans = cnt;
    else break;
    timer++;
  }

  cout << timer << "\n"<< ans;
}