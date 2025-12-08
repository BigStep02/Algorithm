#include <bits/stdc++.h>

using namespace std;

struct egg{
  int hp;
  int weight;
};

int answer = 0;

void back_track(vector<egg> &eggs, int N, int idx){
  if(idx == N){
    int cnt = 0;
    for(int i = 0; i < eggs.size(); i++){
      if(eggs[i].hp <= 0) cnt++;
    }
    answer = max(answer, cnt);  
    return;
  }

  if(eggs[idx].hp <= 0) {
    back_track(eggs, N, idx + 1);
    return;
  }

  bool hit = false;
  
  for(int i = 0; i < eggs.size(); i++){
    if(i == idx or eggs[i].hp <= 0) continue;
    hit = true;
    eggs[idx].hp -= eggs[i].weight;
    eggs[i].hp -= eggs[idx].weight;
    back_track(eggs, N, idx + 1);
    eggs[idx].hp += eggs[i].weight;
    eggs[i].hp += eggs[idx].weight;
  }

  if(!hit) back_track(eggs, N, idx + 1);
  
}

int main(){
  int N; cin >> N;
  vector<egg> eggs(N);
  for(int i = 0; i < N; i++){
    cin >> eggs[i].hp >> eggs[i].weight;
  }

  back_track(eggs, N, 0);
  cout << answer;
}