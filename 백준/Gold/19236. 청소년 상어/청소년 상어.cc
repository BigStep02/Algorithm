#include <bits/stdc++.h>

using namespace std;

struct sharks{
  int x, y, dir;
};

struct fish{
  int size, dir;
};

sharks shark;
int maxVal = INT_MIN;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

pair<int, int> find(vector<vector<fish>> &board, int target){
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      if(board[i][j].size == target) return {i, j};
    }
  }

  return {-1, -1};
}

void swap(vector<vector<fish>> &board, int x1, int y1, int x2, int y2){
  int temp1, temp2;

  temp1 = board[x1][y1].dir;
  temp2 = board[x1][y1].size;

  board[x1][y1].dir = board[x2][y2].dir;
  board[x1][y1].size = board[x2][y2].size;

  board[x2][y2].dir = temp1;
  board[x2][y2].size = temp2;
}

void back_track(vector<vector<fish>> board, sharks shark, int sum){
  maxVal = max(maxVal, sum);

  for(int i = 0; i < 16; i++){
    pair<int, int> fishIndex = find(board, i);
    if(fishIndex.first == -1) continue;
    if(board[fishIndex.first][fishIndex.second].dir == -1) continue;
    int fishDir = board[fishIndex.first][fishIndex.second].dir;
    for(int next = 0; next < 8; next++){
      int dir = (fishDir + next) % 8;
      int nx = fishIndex.first + dx[dir];
      int ny = fishIndex.second + dy[dir];
      if(nx < 0 or nx >= 4 or ny < 0 or ny >= 4) continue;
      if(nx == shark.x and ny == shark.y) continue;
      board[fishIndex.first][fishIndex.second].dir = dir;
      swap(board, nx, ny, fishIndex.first, fishIndex.second);
      break;
    }
  }

  for(int i = 0; i < 3; i++){
    int nx = shark.x + dx[shark.dir] * (i + 1);
    int ny = shark.y + dy[shark.dir] * (i + 1);
    if(nx < 0 or nx >= 4 or ny < 0 or ny >= 4) continue;
    if(board[nx][ny].dir == -1) continue;
    int fishDir = board[nx][ny].dir;
    vector<vector<fish>> tempBoard = board;;
    tempBoard[nx][ny].dir = -1;
    back_track(tempBoard, {nx, ny, fishDir}, sum + board[nx][ny].size + 1);
    tempBoard[nx][ny].dir = fishDir;
  }
}

int main(){
  vector<vector<fish>> board(4, vector<fish>(4));
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      int a, b; cin >> a >> b;
      board[i][j] = {--a, --b};
    }
  }

  shark = {0, 0, board[0][0].dir};
  board[0][0].dir = -1;
  back_track(board, shark, board[0][0].size + 1);

  cout << maxVal;
}