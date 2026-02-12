#include <bits/stdc++.h>

using namespace std;

int main(){
  int testCase; cin >> testCase;

  vector<vector<int>> dp(15, vector<int>(15, 0));

  for(int i = 1; i < 15; i++){
    dp[0][i] = i;
  }

  for(int i = 1; i < 15; i++){
    for(int j = 1; j < 15; j++){
      dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
    }
  }

  for(int t = 0; t < testCase; t++){
    int a, b; cin >> a >> b;

    cout << dp[a][b] << "\n";
  }
}