#include <bits/stdc++.h>

using namespace std;

int main(){
  int testCase; cin >> testCase;

  vector<int> dp(10001);

  dp[0] = 1;
  for(auto a : {1, 2, 3}){
    for(int j = a; j <= 10000; j++){
      dp[j] += dp[j - a];
    }
  }

  while(testCase--){
    int num; cin >> num;

    cout << dp[num] << "\n";
  }
}