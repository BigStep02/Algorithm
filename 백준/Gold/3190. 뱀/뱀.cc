#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<vector<int>> board;
deque<pair<int, int>> snake;
queue<pair<int, char>> rotation;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> K;

  board.resize(N, vector<int>(N, -1));

  for(int i = 0; i < K; i++){
    int x, y; cin >> x >> y;
    board[--x][--y] = 1;
  }

  int L; cin >> L;
  for(int i = 0; i < L; i++){
    int x; char c; cin >> x >> c;
    rotation.push({x, c});
  }

  snake.push_back({0, 0});
  board[0][0] = 2;
  int dir = 0;
  int timer = 0;

  while(true){
    timer++;

    int nx = snake.front().first + dx[dir];
    int ny = snake.front().second + dy[dir];

    if(nx < 0 or nx >= N or ny < 0 or ny >= N or board[nx][ny] == 2) break;
    if(board[nx][ny] == 1){
      board[nx][ny] = 2;
      snake.push_front({nx, ny});
    }
    else{
      board[nx][ny] = 2;
      board[snake.back().first][snake.back().second] = 0;
      snake.pop_back();
      snake.push_front({nx, ny});
    }

    if(!rotation.empty() and rotation.front().first == timer){
      if(rotation.front().second == 'L') dir = (dir + 3) % 4;
      else dir = (dir + 1) % 4;
      rotation.pop();
    }
  }

  cout << timer;
}