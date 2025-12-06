#include <bits/stdc++.h>

using namespace std;

vector<bool> check;
vector<int> permu;
int maxNum = INT_MIN;

void back_track(vector<int> &nums){
  if(permu.size() == nums.size()){
    int plus = 0;
    for(int i = 1; i < permu.size(); i++){
      plus += abs(permu[i - 1] - permu[i]);
    }
    maxNum = max(plus, maxNum);
  }
  
  for(int i = 0; i < nums.size(); i++){
    if(!check[i]){
      permu.push_back(nums[i]);
      check[i] = true;
      back_track(nums);
      permu.pop_back();
      check[i] = false;
    }
  }
}

int main(){
  int N; cin >> N;

  vector<int> nums(N, 0);
  for(int i = 0; i < N; i++){
    cin >> nums[i];
  }
  check.assign(N, false);

  back_track(nums);

  cout << maxNum;
}