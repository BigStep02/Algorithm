#include <bits/stdc++.h>

using namespace std;

struct babyshark{
  int x, y, size, eat, timer;
};

struct shark{
  int x, y, dist;

  bool operator>(const shark &other) const{
    if(dist != other.dist) return dist > other.dist;
    if(x != other.x) return x > other.x;
    return y > other.y;
  }
};

struct Node{
  int x, y;
};

int N;
vector<vector<int>> board;
vector<vector<int>> visited;
babyshark bs;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(priority_queue<shark, vector<shark>, greater<shark>> &pq){
  queue<Node> q;
  visited.assign(N, vector<int>(N, -1));
  q.push({bs.x, bs.y});
  visited[bs.x][bs.y] = 0;
  while(!q.empty()){
    auto [x, y] = q.front();
    q.pop();
    for(int next = 0; next < 4; next++){
      int nx = x + dx[next];
      int ny = y + dy[next];
      if(nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
      if(visited[nx][ny] != -1) continue;
      if(board[nx][ny] > bs.size) continue;
      if(board[nx][ny] < bs.size and board[nx][ny] != 0) pq.push({nx, ny, visited[x][y] + 1});
      visited[nx][ny] = visited[x][y] + 1;
      q.push({nx, ny});
    }
  }
}

int main(){
  cin >> N;

  board.resize(N, vector<int>(N, 0));

  for(int i = 0; i < N ; i++){
    for(int j = 0; j < N; j++){
      cin >> board[i][j];
      if(board[i][j] == 9){
        board[i][j] = 0;
        bs = {i, j, 2, 0, 0};
      }
    }
  }

  while(true){
    priority_queue<shark, vector<shark>, greater<shark>> pq;
    BFS(pq);
    if(pq.empty()){
      cout << bs.timer;
      break;
    } 
    else{
      shark nextEat = pq.top();
      board[nextEat.x][nextEat.y] = 0;
      bs.x = nextEat.x; bs.y = nextEat.y;
      bs.eat++;
      if(bs.eat == bs.size){
        bs.eat = 0;
        bs.size++;
      }
      bs.timer += nextEat.dist;
    }
  }
}