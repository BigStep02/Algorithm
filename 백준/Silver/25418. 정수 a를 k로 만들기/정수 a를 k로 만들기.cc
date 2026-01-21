#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> board;
vector<int> visited;
queue<int> q;

void BFS(){
  while(!q.empty()){
    auto a = q.front();
    q.pop();
    if(a == K){
      cout << visited[a];
      return;
    }

    for(int i = 0; i < 2; i++){
      int next = (i == 0) ? a + 1 : a * 2;
      if(next < 0 or next > K or visited[next] != -1) continue;
      q.push(next);
      visited[next] = visited[a] + 1;
    }
  }
}

int main(){
  cin >> N >> K;

  board.resize(K + 1);
  visited.resize(K + 1, -1);
  q.push(N);
  visited[N] = 0;

  BFS();
}