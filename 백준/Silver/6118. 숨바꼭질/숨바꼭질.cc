#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> graph;
vector<int> visited;
queue<int> q;

void BFS(){
  while(!q.empty()){
    int now = q.front();
    q.pop();

    for(auto &next : graph[now]){
      if(visited[next] != -1) continue;
      visited[next] = visited[now] + 1;
      q.push(next);
    }
  }
}

int main(){
  cin >> N >> M;

  graph.resize(N + 1);
  visited.resize(N + 1, -1);

  for(int i = 0; i < M; i++){
    int a, b; cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  
  q.push(1);
  visited[1] = 0;

  BFS();

  int ansNode, maxDist = 0, cnt = 0;

  for(int i = 1; i <= N; i++){
    if(visited[i] > maxDist){
      ansNode = i;
      maxDist = visited[i];
    }
  }

  for(int i = 1; i <= N; i++){
    if(maxDist == visited[i]) cnt++;
  }

  cout << ansNode << " " << maxDist << " " << cnt;
}