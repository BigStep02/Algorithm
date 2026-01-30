#include <bits/stdc++.h>

using namespace std;

#define Police  100

int N, S, D, F, B, K;
vector<int> board;
vector<int> visited;
queue<int> q;

void BFS(){
  while(!q.empty()){
    int now = q.front();
    q.pop();

    if(now == D){
      cout << visited[D];
      exit(0);
    }

    for(auto &a : {now + F, now - B}){
      if(a <= 0 or a > N or visited[a] != -1 or board[a] == Police) continue;
      visited[a] = visited[now] + 1;
      q.push(a);
    }
  }
}

int main(){
  cin >> N >> S >> D >> F >> B >> K;

  board.resize(N + 1, 0);
  visited.resize(N + 1, -1);

  for(int i = 0; i < K; i++){
    int a; cin >> a;
    board[a] = Police;
  }

  q.push(S);
  visited[S] = 0;
  BFS();

  cout << "BUG FOUND";
}