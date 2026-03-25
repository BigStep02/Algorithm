#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> friends(3);
vector<vector<pair<int, int>>> graph;
vector<vector<int>> dist;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijk(int index){
  while(!pq.empty()){
    auto [cost, now] = pq.top();
    pq.pop();
    if(dist[index][now] < cost) continue;
    for(auto [nextCost, next] : graph[now]){
      int total = cost + nextCost;
      if(total < dist[index][next]){
        dist[index][next] = total;
        pq.push({total, next});
      }
    }
  }
}

int main(){
  cin >> N;
  for(int i = 0; i < 3; i++) cin >> friends[i];
  
  cin >> M;

  graph.resize(N + 1);

  for(int i = 0; i < M; i++){
    int a, b, c; cin >> a >> b >> c;
    graph[a].push_back({c, b});
    graph[b].push_back({c, a});
  }

  dist.assign(3, vector<int>(N + 1, 1e9));

  for(int i = 0; i < friends.size(); i++){
    dist[i][friends[i]] = 0;
    pq.push({0, friends[i]});
    dijk(i);
  }

  int maxIndex = 0;
  int minVal = INT_MIN;

  for(int i = N; i >= 1; i--){
    if(dist[0][i] == 0 or dist[1][i] == 0 or dist[2][i] == 0) continue;
    int minCost = min({dist[0][i], dist[1][i], dist[2][i]});
    if(minVal <= minCost){
      minVal = minCost;
      maxIndex = i;
    }
  }

  cout << maxIndex;
}