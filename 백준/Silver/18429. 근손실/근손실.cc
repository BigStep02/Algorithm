#include <bits/stdc++.h>

using namespace std;

int ans = 0;
int weight = 500;
vector<bool> used;

void backtrack(vector<int> &nums, int index, int M){
  if(weight < 500) return;

  if(index == nums.size()){
    ans++;
    return;
  }
  
  for(int i = 0; i < nums.size(); i++){
    if(used[i]) continue;

    used[i] = true;
    weight += nums[i] - M;
    backtrack(nums, index + 1, M);
    weight -= nums[i] - M;
    used[i] = false;
  }
}

int main(){
  int N, M; cin >> N >> M;

  vector<int> nums(N);
  used.resize(N, false);

  for(int i = 0; i < N; i++) cin >> nums[i];

  backtrack(nums, 0, M);

  cout << ans;
  
}