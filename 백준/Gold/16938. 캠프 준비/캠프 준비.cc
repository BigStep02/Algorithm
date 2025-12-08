#include <bits/stdc++.h>

using namespace std;

vector<int> picked;
int cnt = 0;

void back_track(vector<int> &problems, int N, int L, int R, int X, int idx){
  if(idx == N){
    if(picked.size() >= 2){
      int sum = accumulate(picked.begin(), picked.end(), 0);
      int max_el = *max_element(picked.begin(), picked.end());
      int min_el = *min_element(picked.begin(), picked.end());
      if((sum >= L and sum <= R) and (max_el - min_el >= X)){
        cnt++;
        return;
      }
    }
    return;
  }
  
  picked.push_back(problems[idx]);
  back_track(problems, N, L, R, X, idx + 1);
  picked.pop_back();

  back_track(problems, N, L, R, X, idx + 1);
}

int main(){
  int N, L, R, X; cin >> N >> L >> R >> X;
  
  vector<int> problems(N);
  for(int i = 0; i < N; i++){
    cin >> problems[i];
  }

  back_track(problems, N, L, R, X, 0);

  cout << cnt;
}