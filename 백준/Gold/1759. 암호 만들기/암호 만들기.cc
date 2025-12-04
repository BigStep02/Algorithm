#include <bits/stdc++.h>

using namespace std;

vector<char> back;

void back_track(vector<char> &alpa, int N, int ja, int mo, int idx, int depth){
  if(depth == N){
    if(ja < 2 or mo < 1) return;
    for(auto &a : back) cout << a;
    cout << endl;
    return;
  }

  for(int i = idx; i < alpa.size(); i++){
    back.push_back(alpa[i]);
    if(alpa[i] == 'a' or alpa[i] == 'e' or alpa[i] == 'i' or alpa[i] == 'o' or alpa[i] == 'u') back_track(alpa, N, ja, mo + 1, i + 1, depth + 1);
    else back_track(alpa, N, ja + 1, mo, i + 1, depth + 1);
    back.pop_back();
  }
}

int main(){
  int N, M; cin >> N >> M;
  vector<char> alpa(M);

  for(int i = 0; i < M; i++){
    cin >> alpa[i];
  }

  sort(alpa.begin(), alpa.end());

  back_track(alpa, N, 0, 0, 0, 0);
}