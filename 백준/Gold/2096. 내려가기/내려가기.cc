#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N; cin >> N;

  vector<int> max_dp(3), min_dp(3);
  vector<int> next_max(3), next_min(3);

  for(int i = 0; i < 3; i++){
    cin >> max_dp[i];
    min_dp[i] = max_dp[i];
  }

  for(int i = 1; i < N; i++){
    int a, b, c; cin >> a >> b >> c;

    next_max[0] = max(max_dp[0], max_dp[1]) + a;
    next_max[1] = max({max_dp[0], max_dp[1], max_dp[2]}) + b;
    next_max[2] = max(max_dp[1], max_dp[2]) + c;

    next_min[0] = min(min_dp[0], min_dp[1]) + a;
    next_min[1] = min({min_dp[0], min_dp[1], min_dp[2]}) + b;
    next_min[2] = min(min_dp[1], min_dp[2]) + c;

    max_dp = next_max;
    min_dp = next_min;
  }

  cout << *max_element(max_dp.begin(), max_dp.end()) << " " << *min_element(min_dp.begin(), min_dp.end());
}