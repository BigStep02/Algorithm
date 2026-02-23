#include <bits/stdc++.h>

using namespace std;

struct like{
  int a;
  int b;
  int c;
  int d;
};

struct pos{
  int x, y, likes, empty;

  bool operator<(const pos &diff) const{
    if(likes != diff.likes) return likes < diff.likes;
    if(empty != diff.empty) return empty < diff.empty;
    if(x != diff.x) return x > diff.x;
    return y > diff.y;
  }
};

int N;
vector<like> person;
vector<vector<int>> board;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void find(int per){
  priority_queue<pos> pq;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      int emp = 0;
      int lik = 0;
      if(board[i][j] != 0) continue;
      for(int next = 0; next < 4; next++){
        int nx = i + dx[next];
        int ny = j + dy[next];
        if(nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
        if(board[nx][ny] == 0) emp++;
        else{
          if(board[nx][ny] == person[per].a or board[nx][ny] == person[per].b or board[nx][ny] == person[per].c or board[nx][ny] == person[per].d) lik++;
        }
      }
      pq.push({i, j, lik, emp});
    }
  }
  pos best = pq.top();
  board[best.x][best.y] = per;
}

int sumLike(int per, int x, int y){
  int cnt = 0;
  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
    if(board[nx][ny] == person[per].a or board[nx][ny] == person[per].b or board[nx][ny] == person[per].c or board[nx][ny] == person[per].d) cnt++;
  }

  if(cnt == 0) return 0;
  else if(cnt == 1) return 1;
  else if(cnt == 2) return 10;
  else if(cnt == 3) return 100;
  else return 1000;
}

int main(){
  cin >> N;
  person.resize(N * N + 1);
  board.resize(N, vector<int>(N, 0));

  for(int i = 1; i < N * N + 1; i++){
    int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
    person[a] = {b, c, d, e};
    find(a);
  }

  int ans = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      ans += sumLike(board[i][j], i, j);
    }
  }

  cout << ans;
}