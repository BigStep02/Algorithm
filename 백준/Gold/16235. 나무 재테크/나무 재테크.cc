#include <bits/stdc++.h>

using namespace std;

struct area{
  int feed;
};

struct tree{
  int x, y, age;
  bool isDead = false;
};

int N, M, K;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<vector<area>> board;
vector<vector<int>> feeding;
deque<tree> trees;
vector<tree> deadtrees;

void spring(){
  for(auto &t : trees){
    if(t.isDead) continue;
    
    if(board[t.x][t.y].feed >= t.age){
      board[t.x][t.y].feed -= t.age;
      t.age += 1;
    }
    else {
      t.isDead = true; 
      deadtrees.push_back({t.x, t.y, t.age, t.isDead});
    }
  }
}

void summer(){
  deque<tree> temptree;

  for(auto &t : trees){
    if(t.isDead){
      board[t.x][t.y].feed += t.age / 2;
    }
    else temptree.push_back(t);
  }

  trees = temptree;
}

void autumn(){
  vector<tree> temptree;
  for(auto &t : trees){
    if(t.isDead) continue;
    if(t.age % 5 == 0){
      for(int next = 0; next < 8; next++){
        int nx = t.x + dx[next];
        int ny = t.y + dy[next];
        if(nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
        temptree.push_back({nx, ny, 1, false});
      }
    }
  }

  for(auto &t : temptree){
    trees.push_front({t});
  }

}

void winter(){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      board[i][j].feed += feeding[i][j];
    }
  }
}

int main(){
  cin >> N >> M >> K;

  board.resize(N, vector<area>(N, {5}));
  feeding.resize(N, vector<int>(N, 0));
  
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> feeding[i][j];
    }
  }

  for(int i = 0; i < M; i++){
    int a, b, c; cin >> a >> b >> c;
    trees.push_back({--a, --b, c, false});
  }

  while(K--){
    deadtrees.clear();
    spring();
    summer();
    autumn();
    winter();
  }

  int ans = 0;
  for(auto &t : trees){
    if(!t.isDead) ans++;
  }

  cout << ans;
}