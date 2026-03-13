#include <bits/stdc++.h>

using namespace std;

int main(){
  int tc; cin >> tc;

  while(tc--){
    int N; cin >> N;
    vector<int> cost(N);
    for(int i = 0; i < N; i++){
      cin >> cost[i];
    }

    long long max = cost[cost.size() - 1];
    long long ans = 0;

    for(int i = cost.size() - 2; i >= 0; i--){
      if(cost[i] > max) max = cost[i];
      else if(cost[i] < max) ans += max - cost[i];
    }

    cout << ans << "\n";
  }
}