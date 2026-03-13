#include <bits/stdc++.h>

using namespace std;

struct info{
  int num, dir;
};

struct horse{
  int x, y, dir;
};

vector<horse> horses;
vector<vector<deque<info>>> board;
vector<vector<int>> colorBoard;
int dx[5] = {0 ,0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
int reverseDir[5] = {0, 2, 1, 4, 3};
int N, K;

int main(){
  cin >> N >> K;

  board.resize(N, vector<deque<info>>(N));
  colorBoard.resize(N, vector<int>(N, 0));
  horses.resize(K + 1);

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> colorBoard[i][j];
    } 
  }

  for(int i = 1; i <= K; i++){
    int a, b, c; cin >> a >> b >> c;
    horses[i] = {--a, --b, c};
    board[a][b].push_back({i, c});
  }

  int timer = 0;
  
  while(timer < 1000){
    timer++;

    for(int num = 1; num <= K; num++){
      int x = horses[num].x;
      int y = horses[num].y;

      int pos = 0;
      for(int i = 0; i < board[x][y].size(); i++){
        if(board[x][y][i].num == num){
          pos = i;
          break;
        }
      }

      int nx = x + dx[board[x][y][pos].dir];
      int ny = y + dy[board[x][y][pos].dir];

      if(nx < 0 or nx >= N or ny < 0 or ny >= N or colorBoard[nx][ny] == 2){
        board[x][y][pos].dir = reverseDir[board[x][y][pos].dir];
        
        nx = x + dx[board[x][y][pos].dir];
        ny = y + dy[board[x][y][pos].dir];

        if(nx < 0 or nx >= N or ny < 0 or ny >= N or colorBoard[nx][ny] == 2){
          continue;
        }
      }

      vector<info> moving;

      for(int start = pos; start < board[x][y].size(); start++){
        moving.push_back(board[x][y][start]);
      }

      board[x][y].erase(board[x][y].begin() + pos, board[x][y].end());

      if(colorBoard[nx][ny] == 1) reverse(moving.begin(), moving.end());

      for(auto &t : moving){
        horses[t.num].x = nx;
        horses[t.num].y = ny;
        board[nx][ny].push_back(t);
      }

      if(board[nx][ny].size() >= 4){
        cout << timer;
        return 0;
      }
    }

  }

  cout << -1;
}