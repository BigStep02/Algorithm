#include <bits/stdc++.h>

using namespace std;

struct Node{
  int num, smell;
};

struct shark{
  int num, x, y, dir;
  bool isDead = false;
};

int N, M, K, ans = 0;
vector<vector<Node>> board;
vector<vector<vector<int>>> priDir;
vector<shark> sharks;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void move(){
  for(auto &shark : sharks){
    bool flag = false;
    if(shark.isDead) continue;
    for(auto &next : priDir[shark.num][shark.dir]){
      int nx = shark.x + dx[next];
      int ny = shark.y + dy[next];
      if(nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
      if(board[nx][ny].num != -1) continue;
      shark = {shark.num, nx, ny, next, shark.isDead};
      flag = true;
      break;
    }
    if(!flag){
      for(auto &next : priDir[shark.num][shark.dir]){
        int nx = shark.x + dx[next];
        int ny = shark.y + dy[next];
        if(nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
        if(board[nx][ny].num != shark.num) continue;
        shark = {shark.num, nx, ny, next, shark.isDead};
        break;
      }
    }
  }
}

void delSmell(){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(board[i][j].num != -1){
        board[i][j].smell--;
        if(board[i][j].smell == 0){
          board[i][j] = {-1, -1}; 
        }
      }
    }
  }
}

void spread(){
  for(auto &shark : sharks){
    if(shark.isDead) continue;
    if(board[shark.x][shark.y].num != -1 and board[shark.x][shark.y].num != shark.num){
      shark.isDead = true;
    }
    else{
      board[shark.x][shark.y] = {shark.num, K};
    }
  }
}

bool check(){
  int ans = 0;
  for(auto  &[num, x, y, dir, isDead] : sharks){
    if(!isDead) ans++;
    if(ans >= 2) return true;
  }

  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M >> K;

  board.resize(N, vector<Node>(N, {-1, -1}));
  priDir.resize(M, vector<vector<int>>(4, vector<int>(4, 0)));
  sharks.resize(M);

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      int a; cin >> a;
      if(a > 0){
        board[i][j].num = --a;
        board[i][j].smell = K;
        sharks[a] = {a, i, j, -1};
      }
    }
  }

  for(int i = 0; i < M; i++){
    int a; cin >> a;
    sharks[i].dir = --a;
  }

  for(int i = 0; i < M; i++){
    for(int x = 0; x < 4; x++){
      for(int y = 0; y < 4; y++){
        cin >> priDir[i][x][y];
        priDir[i][x][y]--;
      }
    }
  }

  while(ans < 1000){
    ans++;
    move();
    delSmell();
    spread();
    if(!check()){
      cout << ans;
      return 0; 
    }
  }

  cout << -1;
}