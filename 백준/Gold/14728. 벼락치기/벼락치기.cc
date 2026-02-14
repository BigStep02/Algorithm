#include <bits/stdc++.h>

using namespace std;

int main(){
  int N, T; cin >> N >> T;

  vector<vector<int>> dp(N + 1, vector<int>(T + 1, 0));
  vector<pair<int, int>> study(N + 1);

  for(int i = 1; i <= N; i++){
    int a, b; cin >> a >> b;
    study[i].first = a;
    study[i].second = b;
  }

  for(int i = 1; i <= N; i++){
    for(int j = 0; j <= T; j++){
      if(j >= study[i].first){
        dp[i][j] = max(dp[i - 1][j], study[i].second + dp[i - 1][j - study[i].first]);
      }
      else dp[i][j] = dp[i - 1][j];
    }
  }

  cout << dp[N][T];
}