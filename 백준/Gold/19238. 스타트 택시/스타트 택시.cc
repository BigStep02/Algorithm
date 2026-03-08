#include <bits/stdc++.h>

using namespace std;

struct driver{
  int x, y, gas;
};

struct customer{
  int nowX, nowY, endX, endY, dist;

  bool operator<(const customer &other) const{
    if(dist != other.dist) return dist > other.dist;
    if(nowX != other.nowX) return nowX > other.nowX;
    else return nowY > other.nowY;
  }
};

int N, M, gas;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
driver baek;
vector<vector<int>> board;
vector<vector<pair<int, int>>> cusMap;
vector<vector<int>> visited;
queue<driver> q;

void BFS(priority_queue<customer> &customers){
  while(!q.empty()){
    auto [x, y, gas] = q.front();
    q.pop();
    if(cusMap[x][y].first != -1) customers.push({x, y, cusMap[x][y].first, cusMap[x][y].second, visited[x][y]});
    for(int next = 0; next < 4; next++){
      int nx = x + dx[next];
      int ny = y + dy[next];
      if(nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
      if(visited[nx][ny] != -1 or board[nx][ny] == 1) continue;
      if(visited[x][y] + 1 <= baek.gas){
        visited[nx][ny] = visited[x][y] + 1;
        q.push({nx, ny, 0});
      }
    }
  }
}

void MoveBFS(customer toGo){
  while(!q.empty()){
    auto [x, y, gas] = q.front();
    q.pop();
    if(x == toGo.endX and y == toGo.endY){
      if(baek.gas < visited[x][y]){
        baek.gas = -1;
        return;
      }
      baek.gas -= visited[x][y];
      baek.gas += visited[x][y] * 2;

      baek.x = x;
      baek.y = y;
      return;
    }
    for(int next = 0; next < 4; next++){
      int nx = x + dx[next];
      int ny = y + dy[next];
      if(nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
      if(visited[nx][ny] != -1 or board[nx][ny] == 1) continue;
      visited[nx][ny] = visited[x][y] + 1;
      q.push({nx, ny, baek.gas});
    }
  }
}

int main(){
  cin >> N >> M >> gas;

  board.resize(N, vector<int>(N, 0));
  cusMap.resize(N, vector<pair<int, int>>(N, {-1, -1}));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> board[i][j];
    }
  }

  int x, y; cin >> x >> y;
  baek.x = --x;
  baek.y = --y;
  baek.gas = gas;

  for(int i = 0; i < M; i++){
    int nowX, nowY, endX, endY; cin >> nowX >> nowY >> endX >> endY;
    cusMap[--nowX][--nowY] = {--endX, --endY};
  }

  int cnt = 0;

  while(true){
    priority_queue<customer> customers;
    visited.assign(N, vector<int>(N, -1));
    q = queue<driver>();
    q.push({baek.x, baek.y, 0});
    visited[baek.x][baek.y] = 0;

    BFS(customers);

    if(customers.empty()) break;

    customer toGO = customers.top();
    customers.pop();

    if(toGO.dist > baek.gas){
      baek.gas = -1;
      break;
    }

    baek.gas -= toGO.dist;
    cusMap[toGO.nowX][toGO.nowY] = {-1, -1};
    baek.x = toGO.nowX;
    baek.y = toGO.nowY;

    q = queue<driver>();
    visited.assign(N, vector<int>(N, -1));
    q.push({baek.x, baek.y, 0});
    visited[baek.x][baek.y] = 0;

    MoveBFS(toGO);

    if(visited[toGO.endX][toGO.endY] == -1 or baek.gas < 0){
      baek.gas = -1;
      break;
    } 

    cnt++;
    if(cnt == M) break;
  }

  if(cnt != M) cout << -1;
  else cout << baek.gas;
}