#include <bits/stdc++.h>

using namespace std;

struct coin{
  int x1;
  int y1;
  int x2;
  int y2;
  int count;
};

int N, M;
vector<vector<char>> board;
queue<coin> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(){
  while(!q.empty()){
    auto [x1, y1, x2, y2, count] = q.front();
    q.pop();
    if(count >= 10){
      cout << -1;
      exit(0);
    }
    for(int i = 0; i < 4; i++){
      int coin1dx = x1 + dx[i];
      int coin1dy = y1 + dy[i];
      int coin2dx = x2 + dx[i];
      int coin2dy = y2 + dy[i];
      if(coin1dx < 0 or coin1dx >= N or coin1dy < 0 or coin1dy >= M ){
        if(coin2dx >= 0 and coin2dx < N and coin2dy >= 0 and coin2dy < M){
          cout << count + 1;
          exit(0);
        }
        continue;
      }
      if(coin2dx < 0 or coin2dx >= N or coin2dy < 0 or coin2dy >= M){
        if(coin1dx >= 0 and coin1dx < N and coin1dy >= 0 and coin1dy < M){
          cout << count + 1;
          exit(0);
        }
      }
      if(board[coin1dx][coin1dy] == '#') {
        coin1dx = x1;
        coin1dy = y1;
      }
      if(board[coin2dx][coin2dy] == '#'){
        coin2dx = x2;
        coin2dy = y2;
      }

      q.push({coin1dx, coin1dy, coin2dx, coin2dy, count + 1});
    }
  }
}

int main(){
  cin >> N >> M;

  board.resize(N, vector<char>(M));
  
  vector<pair<int, int>> coins;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> board[i][j];
      if(board[i][j] == 'o'){
        coins.push_back({i, j});
      }
    }
  }

  q.push({coins[0].first, coins[0].second, coins[1].first, coins[1].second, 0});

  bfs();
}