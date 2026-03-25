#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> dp;
vector<int> nums;

int main(){
  cin >> N;

  dp.resize(N + 1, INT_MAX);
  nums.resize(N + 1);

  for(int i = 1; i <= N; i++) cin >> nums[i];

  dp[0] = 0;

  for(int i = 1; i <= N; i++){
    for(int j = 0; j <= i; j++){
      dp[i] = min(dp[i], dp[i - j] + nums[j]);
    }
  }

  cout << dp[N];
}