#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> graph;
vector<int> visited;

void dfs(int node){
  for(int next : graph[node]){
    if(visited[next] != 0) continue;
    visited[next] = 1;
    dfs(next);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;

  graph.resize(N + 1);

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      int a; cin >> a;
      if(a == 1) graph[i].push_back(j);
    }
  }

  for(int i = 1; i <= N; i++){
    visited.assign(N + 1, 0);
    dfs(i);
    for(int j = 1; j < visited.size(); j++){
      cout << visited[j] << " ";
    }
    cout << "\n";
  }
}