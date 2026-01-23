#include <bits/stdc++.h>

using namespace std;

struct Node{
  int to;
  int cost;
};

int N;
long long ans = -1;
vector<vector<Node>> graph;
vector<int> visited;

void DFS(int nowNode, long long nowCost){
  if(nowCost > ans) ans = nowCost;

  for(auto [to, cost] : graph[nowNode]){
    if(visited[to] != -1) continue;
    visited[to] = 1;
    DFS(to, nowCost + cost);
  }
}

int main(){
  cin >> N;
  graph.resize(N + 1);
  visited.resize(N + 1, -1);

  for(int i = 0; i < N - 1; i++){
    int a, b, c; cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }

  visited[1] = 1;
  DFS(1, 0);

  cout << ans;
}