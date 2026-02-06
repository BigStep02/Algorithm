#include <bits/stdc++.h>

using namespace std;

int main(){
  int N; cin >> N;

  vector<int> nums(N + 1);

  for(int i = 1; i <= N; i++){
    cin >> nums[i];
  }

  vector<int> lis;

  lis.push_back(nums[1]);

  for(int i = 2; i <= N; i++){
    if(lis.back() < nums[i])lis.push_back(nums[i]);
    else{
      auto next = lower_bound(lis.begin(), lis.end(), nums[i]);
      *next = nums[i];
    }
  }
  cout << lis.size();
}