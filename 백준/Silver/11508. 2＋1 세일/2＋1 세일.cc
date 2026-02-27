#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N; cin >> N;

  vector<int> prices(N, 0);

  for(int i = 0; i < N; i++){
    cin >> prices[i];
  }

  sort(prices.begin(), prices.end(), greater<int>());

  int ans = 0;

  for(int i = 0; i < N; i++){
    if((i + 1) % 3 != 0) ans += prices[i];
  }

  cout << ans;
}