#include <bits/stdc++.h>

using namespace std;

int main(){
  int N; cin >> N;

  vector<bool> dp(N + 1, true);

  dp[1] = false;
  if(N >= 2) dp[2] = true;

  for(int i = 3; i <= N; i++){
    bool tmp = true;

    if(i - 1 >= 0 and dp[i - 1] == false) tmp = false;
    if(i - 3 >= 0 and dp[i - 3] == false) tmp = false;
    if(i - 4 >= 0 and dp[i - 4] == false) tmp = false;

    dp[i] = !tmp;
  }

  cout << ((dp[N])? "SK" : "CY");
}