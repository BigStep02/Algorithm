#include <bits/stdc++.h>

using namespace std;

int ans = 0;

void back_track(vector<int> &nums, int N, int M, int idx, int plus){
  if(idx == N){
    if(plus == M) ans++;
    return;
  }

  back_track(nums, N, M, idx + 1, plus + nums[idx]);

  back_track(nums, N, M, idx + 1, plus);
}

int main(){
  int N, M; cin >> N >> M;
  vector<int> nums(N);
  for(int i = 0; i < N; i++){
    cin >> nums[i];
  }

  back_track(nums, N, M, 0, 0);
  
  if(M == 0){
    cout << ans - 1;
  }
  else cout << ans;
}