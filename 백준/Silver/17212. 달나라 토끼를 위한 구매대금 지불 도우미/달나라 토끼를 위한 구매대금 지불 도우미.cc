#include <bits/stdc++.h>

using namespace std;

int main(){
  int N; cin >> N;

  vector<int> dp(N + 1);

  dp[0] = 0;
  if(N >= 1) dp[1] = 1;
  if(N >= 2) dp[2] = 1;
  if(N >= 5) dp[5] = 1;
  if(N >= 7) dp[7] = 1;

  for(int i = 3; i <= N; i++){
    if(i >= 2) dp[i] = min(dp[i - 1], dp[i - 2]) + 1;
    if(i >= 5) dp[i] = min({dp[i - 1], dp[i - 2], dp[i - 5]}) + 1;
    if(i >= 7) dp[i] = min({dp[i - 1], dp[i - 2], dp[i - 5], dp[i - 7]}) + 1;
  }

  cout << dp[N];
}