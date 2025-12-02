#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
vector<bool> used;

void back_track(int N, int depth){

  if(depth == N){
    for(int x : ans) cout << x << " ";
    cout << "\n";
    return;
  }

  for(int i = 1; i <= N; i++){
    if(!used[i]){
      used[i] = true;
      ans.push_back(i);
      back_track(N, depth + 1);
      ans.pop_back();
      used[i] = false;
    }
  }
}

int main(){
  int N; cin >> N;
  used.assign(N+1, false);
  back_track(N, 0);
}