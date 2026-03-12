#include <bits/stdc++.h>

using namespace std;

int main(){
  int tc; cin >> tc;

  while(tc--){
    int N; cin >> N;
    map<string, int> clothes;
    for(int i = 0; i < N; i++){
      string a, b; cin >> a >> b;
      clothes[b]++;
    }
    
    int ans = 1;

    for(auto &[style, cloth] : clothes){
      ans *= cloth + 1;
    }

    cout << ans - 1 << "\n";
  }
}