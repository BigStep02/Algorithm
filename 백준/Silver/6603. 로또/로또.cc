#include <bits/stdc++.h>

using namespace std;

void back_track(vector<int> &nums, vector<int> &ans, int N, int now, int depth){

  if(depth == 6){
    for(int i = 0; i < 6; i++){
      cout << ans[i] << " ";
    }
    cout << "\n";
    return;
  }

  for(int i = now; i < N; i++){
    ans.push_back(nums[i]);
    back_track(nums, ans, N, i + 1, depth + 1);
    ans.pop_back();
  }
}

int main(){
  while(true){
    int N; cin >> N;
    if(N == 0) break;
    
    vector<int> nums(N);

    for(int i = 0; i < N; i++){
      cin >> nums[i];
    }
    
    vector<int> ans;

    back_track(nums, ans, N, 0, 0);
    cout << endl;
  }
}