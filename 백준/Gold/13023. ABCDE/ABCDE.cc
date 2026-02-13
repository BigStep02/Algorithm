#include <bits/stdc++.h>

using namespace std;

bool dfs(int idx, vector<vector<int>> &graph, vector<int> &visited, int depth){
  if(depth == 4) return true;

  visited[idx] = 1;

  for(auto &next : graph[idx]){
    if(visited[next] != 0) continue;
    if(dfs(next, graph, visited, depth + 1)) return true;
  }

  visited[idx] = 0;
  return false;
}

int main(){
  int N, M; cin >> N >> M;

  vector<vector<int>> graph(N);

  for(int i = 0; i < M; i++){
    int a, b; cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for(int i = 0; i < N; i++){
    vector<int> visited(N, 0);
    if(dfs(i, graph, visited, 0)){
      cout << 1;
      exit(0);
    }
  }

  cout << 0;
}