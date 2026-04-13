#include <bits/stdc++.h>

using namespace std;

int main(){
  int N; cin >> N;

  vector<vector<int>> score(N, vector<int>(3, 0));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < 3; j++){
      cin >> score[i][j];
    }
  }

  vector<int> nums(score[N - 1][0]);

  sort(score.begin(), score.end(), [](const vector<int> &a, const vector<int> &b){
    return a[2] > b[2];
  });

  int cnt = 0;

  for(int i = 0; i < N; i++){
    if(nums[score[i][0]] >= 2) continue;
    nums[score[i][0]]++;
    cout << score[i][0] << " " << score[i][1] << "\n";
    cnt++;
    if(cnt >= 3) break;
  }
}