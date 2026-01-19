#include <bits/stdc++.h>

using namespace std;

int N, M;
long long ans = -1;
long long graph[11][11];
int visited[11];

void backtrack(int Node, long long time, int cnt){
  if(cnt == N){
    if(graph[Node][0] != -1){
      ans = max(ans, time + graph[Node][0]);
    }
    return;
  }

  for(int i = 1; i <= N; i++){
    if(graph[Node][i] == -1) continue;

    if(visited[i] == 1) continue;

    visited[i] = 1;
    backtrack(i, time + graph[Node][i], cnt + 1);
    visited[i] = -1;
  }
}

int main(){
  cin >> N >> M;

  for(int i = 0; i <= N; i++){
    for(int j = 0; j <= N; j++){
      graph[i][j] = -1;
    }
  }

  for(int i = 0; i < M; i++){
    int a, b;
    long long c; 
    cin >> a >> b >> c;
    if(a == b) continue;
    graph[a][b] = max(graph[a][b], c);
  }

  backtrack(0, 0, 0);

  cout << ans;
}