#include <bits/stdc++.h>

using namespace std;

struct Node{
  int x, y;
};

int N, M;
vector<vector<int>> board;
vector<vector<int>> visited;
queue<Node> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(){
  vector<vector<bool>> airVisited(N, vector<bool>(M, false));
  airVisited[0][0] = true;
  q.push({0, 0});

  while(!q.empty()){
    auto [x, y] = q.front();
    q.pop();
    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 0 or nx >= N or ny < 0 or ny >= M) continue;
      if(board[nx][ny] == 1){
        visited[nx][ny]++;
        continue;
      }
      if(!airVisited[nx][ny]){
        airVisited[nx][ny] = true;
        q.push({nx, ny});
      }
    }
  }
}

void meltCheese(){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(visited[i][j] >= 2){
        board[i][j] = 0;
      }
    }
  }
}

bool check(){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(board[i][j] != 0) return false;
    }
  }

  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;

  board.resize(N, vector<int>(M, 0));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> board[i][j];
    }
  }

  
  int timer = 0;
  while(true){
    if(check()) break;
    visited.assign(N, vector<int>(M, 0));
    BFS();
    meltCheese();

    timer++;
  }

  cout << timer;
}