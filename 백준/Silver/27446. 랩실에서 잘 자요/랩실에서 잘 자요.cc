#include <bits/stdc++.h>

using namespace std;

int main(){
  int N, M; cin >> N >> M;

  vector<bool> page(N + 1, false);

  for(int i = 1; i <= M; i++){
    int a; cin >> a;

    if(!page[a]) page[a] = true;
  }

  vector<int> dp(N + 1, 0);

  for(int i = 1; i <= N; i++){
    if(page[i]) dp[i] = dp[i - 1];
    else dp[i] = dp[i - 1] + 7;
    for(int j = i; j > 0; j--){
      int printPage = i - j + 1;
      int cost = dp[j - 1] + 5 + 2 * printPage;
      dp[i] = min(dp[i], cost);
      if(dp[j - 1] + 5 >= dp[i]) break;
    }
  }

  cout << dp[N];
}