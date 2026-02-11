#include <bits/stdc++.h>

using namespace std;

int main(){
  int N; cin >> N;
 
  vector<int> board(N + 1);

  for(int i = 1; i <= N; i++) cin >> board[i];

  vector<int> dp(N + 1, 0);

  dp[N] = 1;
  dp[N - 1] = 1;

  for(int i = N - 1; i > 0; i--){
    if(i + board[i] + 1 <= N){
      dp[i] = dp[i + board[i] + 1] + 1;
    }
    else dp[i] = 1;
  }

  for(int i = 1; i <= N; i++){
    cout << dp[i] << " ";
  }
}