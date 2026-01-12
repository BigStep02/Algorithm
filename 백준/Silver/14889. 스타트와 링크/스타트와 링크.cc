#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> teamPower;
vector<bool> used;
int ans = INT_MAX;

int calcul(){
  int team1 = 0, team2 = 0;

  for(int i = 0; i < used.size(); i++){
    for(int j = i + 1; j < used.size(); j++){
      if(used[i] && used[j]) team1 += teamPower[i][j] + teamPower[j][i];
      else if(!used[i] && !used[j]) team2 += teamPower[i][j] + teamPower[j][i];
    }
  }

  return team1 - team2;
}

void backtrack(int idx, int cnt){
  if(cnt == used.size() / 2){
    ans = min(ans, abs(calcul()));
    return;
  }

  if(idx == used.size()) return;

  used[idx] = true;
  backtrack(idx + 1, cnt + 1);
  used[idx] = false;
  backtrack(idx + 1, cnt);
}

int main(){
  int N; cin >> N;

  teamPower.resize(N, vector<int>(N, 0));
  used.resize(N, false);
  used[0] = true;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> teamPower[i][j];
    }
  }

  backtrack(1, 1);

  cout << ans;
}