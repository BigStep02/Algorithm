#include <bits/stdc++.h>

using namespace std;

struct Node{
  int x;
  int y;
};

void BFS(const vector<string> &board, vector<vector<int>> &visited, deque<Node> &dq, int N, int M, int destX, int destY){
  const int dx[] = {1, -1, 0, 0};
  const int dy[] = {0, 0, 1, -1};

  while(!dq.empty()){
    auto [x, y] = dq.front();
    dq.pop_front();

    for(int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];

      if(nx < 0 or nx >= N or ny < 0 or ny >= M) continue;

      int nextCost = visited[x][y] + (board[nx][ny] == '1');

      if(nextCost < visited[nx][ny]){
        visited[nx][ny] = nextCost;
        if(board[nx][ny] == '0'){
          dq.push_back({nx, ny});
        } else {
          dq.push_front({nx, ny});
        }
      }
    }
  }

  cout << visited[destX][destY] + 1 << "\n";
}

int main(){
  int N, M; cin >> N >> M;
  int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

  vector<string> board(N);
  for(int i = 0; i < N; i++) {
    cin >> board[i];
  }

  vector<vector<int>> visited(N, vector<int>(M, INT_MAX));

  deque<Node> dq;
  dq.push_back({x1 - 1, y1 - 1});
  visited[x1 - 1][y1 - 1] = 0;

  BFS(board, visited, dq, N, M, x2 - 1, y2 - 1);
}