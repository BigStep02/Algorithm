#include <bits/stdc++.h>

using namespace std;

int main(){
  int N, M; cin >> N >> M;

  vector<vector<int>> board(N + 1, vector<int>(M + 1));

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++){
      cin >> board[i][j];
    }
  }

  vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++){
      dp[i][j] = board[i][j] + max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
    }
  }

  cout << dp[N][M];
}