#include <bits/stdc++.h>

using namespace std;

#define UP  1
#define DOWN  2
#define RIGHT 3
#define LEFT  4

struct shark{
  int x, y, speed, dir, size;
  bool isDead = false;
};

vector<shark> sharks;
int N, M, T;
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};

int catchShark(int person){
  int targetIdx = -1;
  int target = INT_MAX;

  for(int i = 0; i < sharks.size(); i++){
    if(sharks[i].isDead) continue;
    if(sharks[i].y == person and sharks[i].x < target){
      targetIdx = i;
      target = sharks[i].x;
    }
  }

  if(targetIdx != -1){
    sharks[targetIdx].isDead = true;
    return sharks[targetIdx].size;
  }
  return 0;
}

void moveShark(){
  for(int i = 0; i < sharks.size(); i++){
    if(sharks[i].isDead) continue;

    int dist = sharks[i].speed;
    if(sharks[i].dir <= 2) dist %= (2 * (N - 1));
    else dist %= (2 * (M - 1));

    for(int next = 0; next < dist; next++){
      int nx = sharks[i].x + dx[sharks[i].dir];
      int ny = sharks[i].y + dy[sharks[i].dir];
      if(nx < 0 or nx >= N or ny < 0 or ny >= M){
        if(sharks[i].dir == UP) sharks[i].dir = DOWN;
        else if(sharks[i].dir == DOWN) sharks[i].dir = UP;
        else if(sharks[i].dir == RIGHT) sharks[i].dir = LEFT;
        else sharks[i].dir = RIGHT;
        nx = sharks[i].x + dx[sharks[i].dir];
        ny = sharks[i].y + dy[sharks[i].dir];
      }
      sharks[i].x = nx;
      sharks[i].y = ny;
    }
  }

  vector<vector<int>> board(N, vector<int>(M, -1));

  for(int i = 0; i < sharks.size(); i++){
    if(sharks[i].isDead) continue;

    int x = sharks[i].x;
    int y = sharks[i].y;

    if(board[x][y] == -1) board[x][y] = i;
    else{
      int preIdx = board[x][y];
      if(sharks[preIdx].size >= sharks[i].size) sharks[i].isDead = true;
      else {
        board[x][y] = i;
        sharks[preIdx].isDead = true;
      }
    }
  }
}

int main(){
  cin >> N >> M >> T;

  for(int i = 0; i < T; i++){
    int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
    sharks.push_back({--a, --b, c, d, e});
  }

  int maxSize = 0;

  for(int person = 0; person < M; person++){
    maxSize += catchShark(person);
    moveShark();
  }

  cout << maxSize;
}