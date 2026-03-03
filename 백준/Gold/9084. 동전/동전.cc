#include <bits/stdc++.h>

using namespace std;

int main(){
  int testCase; cin >> testCase;

  while(testCase--){
    int N; cin >> N;
    vector<int> coins(N);

    for(int i = 0; i < N; i++){
      cin >> coins[i];
    }

    int a; cin >> a;

    vector<int> money(a + 1, 0);

    money[0] = 1;

    for(int i = 0; i < coins.size(); i++){
      for(int j = coins[i]; j <= a; j++){
        money[j] += money[j - coins[i]];
      }
    }
    cout << money[a] << "\n";
  }
}