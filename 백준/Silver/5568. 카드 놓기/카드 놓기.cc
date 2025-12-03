#include <bits/stdc++.h>

using namespace std;

vector<bool> used;
vector<string> permu;
unordered_set<string> uniqueNum;

void back_track(vector<string> &nums, int K, int depth){
  if(K == depth){
    string s;
    for(auto &a : permu) s += a;
    uniqueNum.insert(s);
    return;
  }

  for(int i = 0; i < nums.size(); i++){
    if(!used[i]){
      permu.push_back(nums[i]);
      used[i] = true;
      back_track(nums, K, depth + 1);
      permu.pop_back();
      used[i] = false;
    }
  }
}

int main(){
  int N, K; cin >> N >> K;

  vector<string> nums(N, "");
  for(int i = 0; i < N; i++){
    cin >> nums[i];
  }

  used.assign(N, false);
  
  back_track(nums, K, 0);
  cout << uniqueNum.size();
}