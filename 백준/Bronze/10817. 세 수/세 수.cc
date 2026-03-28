#include <bits/stdc++.h>

using namespace std;

vector<int> nums(3);

int main(){
  for(int i = 0; i < 3; i++){
    cin >> nums[i];
  }

  sort(nums.begin(), nums.end());

  cout << nums[1];
}