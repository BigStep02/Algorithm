#include <bits/stdc++.h>

using namespace std;

int main(){
  int N; cin >> N;

  vector<int> cardPrice(N + 1, 0);
  for(int i = 1; i <= N; i++){
    cin >> cardPrice[i];
  }

  vector<int> dp(N + 1, 0);

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= i; j++){
      dp[i] = max(dp[i], cardPrice[j] + dp[i - j]);
    }
  }

  cout << dp[N];
}