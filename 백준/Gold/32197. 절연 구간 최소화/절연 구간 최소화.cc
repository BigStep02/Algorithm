#include <bits/stdc++.h>

using namespace std;

struct Edge{
  int to;
  int cost;
};

void BFS(vector<vector<Edge>> &graph, vector<vector<int>> &visited, deque<Edge> &dq, int N, int start, int end){
  while(!dq.empty()){
    auto current = dq.front();
    dq.pop_front();

    for(auto &next : graph[current.to]){
      int add = (current.cost != next.cost);
      if(visited[next.to][next.cost] > visited[current.to][current.cost] + add){
        visited[next.to][next.cost] = visited[current.to][current.cost] + add;
        if(add == 0) dq.push_front(Edge{next.to, next.cost});
        else dq.push_back(Edge{next.to, next.cost});
      }
    }
  }
}

int main(){
  int N, M; cin >> N >> M;

  vector<vector<Edge>> graph(N + 1);

  for(int i = 0; i < M; i++){
    int A, B, C; cin >> A >> B >> C;

    graph[A].push_back(Edge{B, C});
    graph[B].push_back(Edge{A, C});
  }

  int start, end; cin >> start >> end;

  vector<vector<int>> visited(N + 1, vector<int>(2, INT_MAX));
  deque<Edge> dq;

  visited[start][0] = 0, visited[start][1] = 0;
  dq.push_back(Edge{start, 0});
  dq.push_back(Edge{start, 1});

  BFS(graph, visited, dq, N, start, end);

  int ans = min(visited[end][0], visited[end][1]);
  cout << (ans == INT_MAX ? -1 : ans) << endl;
}