#include <bits/stdc++.h>

using namespace std;

int main(){
  int N; cin >> N;

  vector<bool> dp(N + 1, 0);

  dp[1] = true;
  dp[2] = false;
  dp[3] = true;

  for(int i = 4; i <= N; i++){
    if(!dp[i - 1] or !dp[i - 3]) dp[i] = true;
    else dp[i] = false;
  }

  cout << ((dp[N])? "SK" : "CY");
}