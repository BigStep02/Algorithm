#include <bits/stdc++.h>

using namespace std;

int N, cnt = 0;
vector<int> nums;

int main(){
  cin >> N;

  nums.resize(N);

  for(int i = 0; i < N; i++){
    cin >> nums[i];
  }

  sort(nums.begin(), nums.end());

  for(int i = 0; i < nums.size(); i++){
    int left = 0;
    int right = nums.size() - 1;

    while(left < nums.size() and right >= 0 and left < right){
      if(left == i){
        left++;
        continue;
      }
      if(right == i){
        right--;
        continue;
      }
      int next = nums[left] + nums[right];
      if(next == nums[i]){
        cnt++;
        break;
      } 
      else if(next < nums[i]) left++;
      else right--;
    }
  }

  cout << cnt;
}