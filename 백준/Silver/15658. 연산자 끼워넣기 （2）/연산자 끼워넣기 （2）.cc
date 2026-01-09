#include <bits/stdc++.h>

using namespace std;

vector<int> nums;
vector<int> calcul(4, 0);
long long max_val = LLONG_MIN, min_val = LLONG_MAX;

void backtrack(int idx, long long now){
  if (idx == nums.size()){
    max_val = max(max_val, now);
    min_val = min(min_val, now);
    return;
  }

  for(int i = 0; i < 4; i++){
    if(calcul[i] <= 0) continue;

    calcul[i]--;
    if(i == 0) backtrack(idx + 1, now + nums[idx]);
    else if(i == 1) backtrack(idx + 1, now - nums[idx]);
    else if(i == 2) backtrack(idx + 1, now * nums[idx]);
    else backtrack(idx + 1, now / nums[idx]);
    calcul[i]++;
  }
}

int main(){
  int N; cin >> N;
  nums.resize(N);

  for(int i = 0; i < N; i++) cin >> nums[i];

  for(int i = 0; i < 4; i++) cin >> calcul[i];

  backtrack(1, nums[0]);

  cout << max_val << "\n" << min_val;
}