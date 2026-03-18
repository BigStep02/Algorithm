#include <bits/stdc++.h>

using namespace std;

int N, M, R, maxVal = 0;
vector<int> item;
vector<vector<pair<int, int>>> graph;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> dist;

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
  cin >> N >> M >> R;

  item.resize(N + 1);
  graph.resize(N + 1, vector<pair<int, int>>());

  for(int i = 1; i <= N; i++){
    cin >> item[i];
  }

  for(int i = 0; i < R; i++){
    int a, b, c; cin >> a >> b >> c;
    graph[a].push_back({c, b});
    graph[b].push_back({c, a});
  }

  for(int i = 1; i <= N; i++){
    dist.assign(N + 1, INT_MAX);
    pq.push({0, i});
    dist[i] = 0;
    dijk();
    int cnt = 0;
    for(int i = 1; i <= N; i++){
      if(dist[i] <= M) cnt += item[i];
    }
    maxVal = max(maxVal, cnt);
  }

  cout << maxVal;
}