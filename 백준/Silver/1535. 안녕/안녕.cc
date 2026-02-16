#include <bits/stdc++.h>

using namespace std;

int main(){
  int N; cin >> N;

  vector<int> dp(101, 0);
  vector<int> getHp(N + 1);
  vector<int> loseHp(N + 1);

  for(int i = 1; i <= N; i++){
    cin >> loseHp[i];
  }
  for(int i = 1; i <= N; i++){
    cin >> getHp[i];
  }

  for(int i = 1; i <= N; i++){
    for(int j = 100; j > loseHp[i]; j--){
      dp[j] = max(dp[j], getHp[i] + dp[j - loseHp[i]]);
    }
  }

  cout << dp[100];
}