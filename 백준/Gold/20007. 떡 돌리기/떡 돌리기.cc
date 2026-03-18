#include <bits/stdc++.h>

using namespace std;

int N, M, X, Y;
vector<vector<pair<int, int>>> graph;
vector<int> dist;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijk(){
  while(!pq.empty()){
    auto [cost, now] = pq.top();
    pq.pop();
    if(dist[now] < cost) continue;
    for(auto &next : graph[now]){
      int total = cost + next.first;
      if(total < dist[next.second]){
        dist[next.second] = total;
        pq.push({total, next.second});
      }
    }
  }
}

int main(){
  cin >> N >> M >> X >> Y;
  
  graph.resize(N, vector<pair<int, int>>());
  dist.resize(N, INT_MAX);

  for(int i = 0; i < M; i++){
    int a, b, c; cin >> a >> b >> c;
    graph[a].push_back({c, b});
    graph[b].push_back({c, a});
  }

  dist[Y] = 0;
  pq.push({0, Y});

  dijk();

  sort(dist.begin(), dist.end());

  int days = 1, hp = X;

  for(int i = 0; i < N; i++){
    if(dist[i] * 2 > X){
      cout << -1;
      return 0;
    }
    if(dist[i] * 2 <= hp){
      hp -= dist[i] * 2;
    }
    else {
      days++;
      hp = X - dist[i] * 2;
    }
  }

  cout << days;
}