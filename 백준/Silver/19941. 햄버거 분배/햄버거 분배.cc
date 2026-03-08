#include <bits/stdc++.h>

using namespace std;

int main(){
  int N, K; cin >> N >> K;

  string roca; cin >> roca;
  vector<bool> isEat(roca.size(), false);

  int ans = 0;

  for(int i = 0; i < roca.size(); i++){
    if(roca[i] == 'P'){
      for(int j = i - K; j <= i + K; j++){
        if(j < 0 or j >= roca.size()) continue;
        if(roca[j] == 'H' and !isEat[j]){
          isEat[j] = true;
          ans++;
          break;
        }
      }
    }
  }

  cout << ans;
}