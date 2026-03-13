#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<pair<int, int>>> graph;
vector<int> dist;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void deik(){
  while(!pq.empty()){
    auto [cost, now] = pq.top();
    pq.pop();
    if(dist[now] < cost) continue;
    for(auto &[next, nextCost] : graph[now]){
      int total = cost + nextCost;
      if(total < dist[next]){
        dist[next] = total;
        pq.push({total, next});
      }
    }
  }
}

int main(){
  cin >> N >> M;

  graph.assign(N + 1, vector<pair<int, int>>());
  dist.assign(N + 1, INT_MAX);

  for(int i = 0; i < M; i++){
    int a, b, c; cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }

  pq.push({0, 1});
  dist[1] = 0;

  deik();

  cout << dist[N];
}