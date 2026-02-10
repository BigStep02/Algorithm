#include <bits/stdc++.h>

using namespace std;

int main(){
  int N, M; cin >> N >> M;

  vector<vector<int>> board(N + 1, vector<int>(M + 1, 0));

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++){
      cin >> board[i][j];
    }
  }

  vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(M + 1, vector<int>(3, 1e9)));

  for(int i = 1; i <= M; i++){
    for(int j = 0; j < 3; j++){
      dp[1][i][j] = board[1][i];
    }
  }

  for(int i = 2; i <= N; i++){
    for(int j = 1; j <= M; j++){
      if(j > 1){
        dp[i][j][0] = min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + board[i][j];
      }
      dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + board[i][j];
      if(j < M){
        dp[i][j][2] = min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]) + board[i][j];
      }
    }
  }

  int ans = INT_MAX;

  for(int i = 1; i <= M; i++){
    for(int j = 0; j < 3; j++){
      ans = min(ans, dp[N][i][j]);
    }
  }

  cout << ans;
}