#include <bits/stdc++.h>

using namespace std;

struct Node{
  int x;
  int max;
};

int N;
vector<int> board;
vector<int> visited;
queue<Node> q;

void BFS(){
  while(!q.empty()){
    auto [x, max] = q.front();
    q.pop();
    if(x == N - 1){
      cout << visited[N - 1] - 1;
      exit(0);
    }
    for(int i = 1; i <= max; i++){
      int next = x + i;
      if(next < 0 or next >= N or visited[next] != -1) continue;
      visited[next] = visited[x] + 1;
      q.push({next, board[next]});
    }
  }
}

int main(){
 cin >> N;
 board.resize(N);
 visited.resize(N, -1);

 if(N == 1){
  cout << 0;
  exit(0);
 }

 for(int i = 0; i < N; i++){
  cin >> board[i];
 }

 visited[0] = 1;
 for(int i = 1; i <= board[0]; i++){
  q.push({0, i});
 }

 BFS();

 cout << -1;
}