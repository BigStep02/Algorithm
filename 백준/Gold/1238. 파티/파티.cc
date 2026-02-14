#include <bits/stdc++.h>

using namespace std;

struct nextNode{
  int to;
  int cost;
};

int N, M, X;
vector<vector<nextNode>> graph;
vector<int> visited;

void dijk(int startNode){
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, startNode});
  visited[startNode] = 0;

  while(!pq.empty()){
    int totalCost = pq.top().first;
    int nowNode = pq.top().second;
    pq.pop();
    for(nextNode &edge : graph[nowNode]){
      int nextNode = edge.to;
      int nextCost = edge.cost;
      if(visited[nextNode] > totalCost + nextCost){
        visited[nextNode] = totalCost + nextCost;
        pq.push({totalCost + nextCost, nextNode});
      }
    }
  }
}

int main(){
  cin >> N >> M >> X;

  graph.resize(N + 1);

  for(int i = 0; i < M; i++){
    int a, b, c; cin >> a >> b >> c;
    graph[a].push_back({b, c});
  }

  int ans = 0;

  for(int i = 1; i <= N; i++){
    int nowNodeCost = 0;
    visited.assign(N + 1, INT_MAX);
    dijk(i);
    nowNodeCost += visited[X];
    visited.assign(N + 1, INT_MAX);
    dijk(X);
    nowNodeCost += visited[i];
    ans = max(ans, nowNodeCost);
  }

  cout << ans;
}