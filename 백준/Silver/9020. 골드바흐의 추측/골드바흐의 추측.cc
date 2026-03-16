#include <bits/stdc++.h>

using namespace std;

int main(){
  int tc; cin >> tc;

  while(tc--){
    int N; cin >> N;
    vector<bool> pn(N + 1, false);
    vector<int> primeNumber;
  
    pn[0] = true;
    pn[1] = true;
    
    for(int i = 2; i <= sqrt(N); i++){
      if(pn[i]) continue;
      for(int j = i * i; j <= N; j += i){
        pn[j] = true;
      }
    }

    for(int i = N / 2; i >= 2; i--){
      if(!pn[i] and !pn[N - i]){
        cout << i << " " << N - i << "\n";
        break;
      }
    }
  }
}