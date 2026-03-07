#include <bits/stdc++.h>

using namespace std;

int N, Q, ans = 0, area = 0;
vector<vector<int>> board;
vector<vector<int>> visited;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int i, int j){
  queue<pair<int, int>> q;
  q.push({i, j});
  visited[i][j] = 1;
  int cnt = 1;
  while(!q.empty()){
    auto [x, y] = q.front();
    q.pop();
    for(int next = 0; next < 4; next++){
      int nx = x + dx[next];
      int ny = y + dy[next];
      if(nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
      if(visited[nx][ny] != 0 or board[nx][ny] <= 0) continue;
      cnt++;
      visited[nx][ny] = 1;
      q.push({nx, ny});
    }
  } 

  return cnt;
}

int main(){
  cin >> N >> Q;

  N = 1 << N;

  board.resize(N, vector<int>(N, 0));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> board[i][j];
    }
  }

  while(Q--){
    int L; cin >> L;
    L = 1 << L;
    vector<vector<int>> tempBoard(N, vector<int>(N, 0));
    for(int ix = 0; ix < N; ix += L){
      for(int iy = 0; iy < N; iy += L){
        for(int x = 0; x < L; x++){
          for(int y = 0; y < L; y++){
            tempBoard[ix + y][iy + L - x - 1] = board[ix + x][iy + y];
          }
        }
      }
    }

    board = tempBoard;

    vector<pair<int, int>> melt;

    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        int ans = 0;
        for(int next = 0; next < 4; next++){
          int nx = i + dx[next];
          int ny = j + dy[next];
          if(nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
          if(board[nx][ny] > 0) ans++;
        }
        if(ans < 3) melt.push_back({i, j});
      }
    }

    for(auto p : melt) board[p.first][p.second]--;
  }

  visited.resize(N, vector<int>(N, 0));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(board[i][j] > 0){
        area += board[i][j];
        if(visited[i][j] == 0){
          ans = max(ans, bfs(i, j));
        }
      }
    }
  }

  cout << area << "\n" << ans;
}