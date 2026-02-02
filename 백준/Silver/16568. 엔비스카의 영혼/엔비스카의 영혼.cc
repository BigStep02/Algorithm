#include <bits/stdc++.h>

using namespace std;

int main(){
  int N, A, B;
  
  cin >> N >> A >> B;

  vector<int> dp(N + 1, INT_MAX);

  dp[0] = 0;

  for(int i = 1; i <= N; i++){
    dp[i] = dp[i - 1] + 1;
    if(i - 1 - A >= 0){
      dp[i] = min(dp[i], dp[i - 1 - A] + 1);
    }
    if(i - 1 - B >= 0){
      dp[i] = min(dp[i], dp[i - 1 - B] + 1);
    }
  }

  cout << dp[N];
}