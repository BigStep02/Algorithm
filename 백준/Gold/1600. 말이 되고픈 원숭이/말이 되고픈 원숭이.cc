#include <bits/stdc++.h>

using namespace std;

const int dx[12] = {1, -1, 0, 0, -1, -2, -2, -1, 1,  2, 2, 1};
const int dy[12] = {0, 0, 1, -1, -2, -1, 1, 2, -2, -1, 1, 2};

struct Node{
  int x;
  int y;
  int jump;
};

void BFS(vector<vector<int>>& board, vector<vector<vector<int>>>& visited, queue<Node>& q, int N, int M, int K) {
  while(!q.empty()){
    auto [x, y, jump] = q.front();
    q.pop();

    if(x == N - 1 && y == M - 1){
      cout << visited[x][y][jump] - 1 << endl;
      return;
    }

    for(int dir = 0; dir < 12; dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];

      if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
      
      if(dir < 4){
        if(board[nx][ny] == 0 && visited[nx][ny][jump] == 0){
          visited[nx][ny][jump] = visited[x][y][jump] + 1;
          q.push({nx, ny, jump});
        }
      }
      else{
        if(dir > 3 && board[nx][ny] == 0 && jump < K && visited[nx][ny][jump + 1] == 0){
          visited[nx][ny][jump + 1] = visited[x][y][jump] + 1;
          q.push({nx, ny, jump + 1});
        }
      }
    }
  }

  cout << -1 << endl;
}

int main(){
  int K, N, M;
  cin >> K >> M >> N;

  vector<vector<int>> board(N, vector<int>(M, 0));
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> board[i][j];
    }
  }

  vector<vector<vector<int>>> visited(N, vector<vector<int>>(M, vector<int>(K + 1, 0)));
  queue<Node> q;
  q.push({0, 0, 0});
  visited[0][0][0] = 1;

  BFS(board, visited, q, N, M, K);
}