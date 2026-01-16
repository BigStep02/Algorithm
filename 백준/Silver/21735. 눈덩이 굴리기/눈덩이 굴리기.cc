#include <bits/stdc++.h>

using namespace std;

int N, M, ans = 0;
vector<int> snow_size;

void backtrack(int idx, int snow, int time){\
  if(time == M){
    ans = max(ans, snow);
    return;
  }

  if(idx + 1 >= snow_size.size()){
    ans = max(ans, snow);
    return;
  }

  backtrack(idx + 1, snow + snow_size[idx + 1], time + 1);
  
  if(idx + 2 < snow_size.size()){
    backtrack(idx + 2, snow / 2 + snow_size[idx + 2], time + 1);
  }
}

int main(){
  cin >> N >> M;

  snow_size.resize(N);
  for(int i = 0; i < N; i++) cin >> snow_size[i];

  backtrack(-1, 1, 0);

  cout << ans;
}