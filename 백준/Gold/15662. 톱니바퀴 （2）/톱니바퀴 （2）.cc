#include <bits/stdc++.h>

using namespace std;

int N;
deque<deque<int>> dq;
vector<int> rotation;

void chain_rotation(int idx){
  if(rotation[idx] == 1){
    dq[idx].push_front(dq[idx].back());
    dq[idx].pop_back();
  }
  else{
    dq[idx].push_back(dq[idx].front());
    dq[idx].pop_front();
  }
}

int main(){
  cin >> N;
  dq.resize(N);

  for(int i = 0; i < N; i++){
    string S; cin >> S;
    for(int j = 0; j < S.size(); j++){
      dq[i].push_back(S[j] - '0');
    }
  }

  int T; cin >> T;

  while(T--){
    rotation.assign(N, 0);
    int num, dir; cin >> num >> dir;
    rotation[--num] = dir;

    for(int i = num; i < N - 1; i++){
      if(dq[i][2] != dq[i + 1][6]) rotation[i + 1] = -rotation[i];
    }
    for(int i = num; i > 0; i--){
      if(dq[i][6] != dq[i - 1][2]) rotation[i - 1] = -rotation[i];
    }

    for(int i = 0; i < rotation.size(); i++){
      if(rotation[i] == 0) continue;
      chain_rotation(i);
    }
  }

  int cnt = 0;

  for(int i = 0; i < dq.size(); i++){
    if(dq[i].front() == 1) cnt++;
  }

  cout << cnt;
}