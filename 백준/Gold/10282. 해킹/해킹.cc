#include <bits/stdc++.h>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void deik(){
  while(!pq.empty()){
    auto [cost, now] = pq.top();
    pq.pop();
    if(dist[now] < cost) continue;
    for(auto [next, nextCost] : graph[now]){
      int total = cost + nextCost;
      if(total < dist[next]){
        dist[next] = total;
        pq.push({total, next});
      }
    }
  }
}

int main(){
  int tc; cin >> tc;

  while(tc--){
    int N, D, C; cin >> N >> D >> C;
    graph.assign(N + 1, vector<pair<int, int>>());

    for(int i = 0; i < D; i++){
      int a, b, c; cin >> a >> b >> c;
      graph[b].push_back({a, c});
    }

    dist.assign(N + 1, INT_MAX);
    pq.push({0, C});
    dist[C] = 0;
    deik();

    int comCnt = 0, time = 0;

    for(int i = 1; i <= N; i++){
      if(dist[i] != INT_MAX){
        comCnt++;
        time = max(time, dist[i]);
      }
    }
    cout << comCnt << " " << time << "\n";
  }
} 