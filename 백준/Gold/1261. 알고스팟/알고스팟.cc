#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

struct Node{
  int x;
  int y;
};

void BFS(const vector<string> & board, vector<vector<int>>& visited, deque<Node>& q, int N, int M, int maxWall) {
  while(!q.empty()){
    auto [x, y] = q.front();
    q.pop_front();

    for(int dir = 0; dir < 4; dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];

      if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

      int nextCost = visited[x][y] + (board[nx][ny] == '1');

      if(nextCost < visited[nx][ny]){
        visited[nx][ny] = nextCost;
        if(board[nx][ny] == '1'){
          q.push_back({nx, ny});
        } else {
          q.push_front({nx, ny});
        }
      }
    }
  }
  cout << visited[N-1][M-1] - 1;
}

int main(){
  int N, M, wallCnt = 0;
  cin >> M >> N;

  vector<string> board(N, "");
  for(int i = 0; i < N; i++){
    cin >> board[i];
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(board[i][j] == '1') wallCnt++;
    }
  }

  vector<vector<int>> visited(N, vector<int>(M, INT_MAX));

  deque<Node> q;
  q.push_back({0, 0});
  visited[0][0] = 1;
  BFS(board, visited, q, N, M, wallCnt);
} 