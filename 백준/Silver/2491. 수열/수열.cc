#include <bits/stdc++.h>

using namespace std;

int main(){
  int N; cin >> N;
  vector<int> nums(N + 1);

  for(int i = 1; i <= N; i++){
    cin >> nums[i];
  }

  vector<int> incDp(N + 1, 0);
  vector<int> decDp(N + 1, 0);
  incDp[1] = 1;
  decDp[1] = 1;

  for(int i = 2; i <= N; i++){
    if(nums[i - 1] > nums[i]){
       decDp[i] = decDp[i - 1] + 1;
       incDp[i] = 1;
    }
    else if(nums[i - 1] == nums[i]){
      incDp[i] = incDp[i - 1] + 1;
      decDp[i] = decDp[i - 1] + 1;
    }
    else {
      incDp[i] = incDp[i - 1] + 1;
      decDp[i] = 1;
    }
  }

  cout << max(*max_element(incDp.begin(), incDp.end()), *max_element(decDp.begin(), decDp.end()));
}