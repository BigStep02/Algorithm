#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<pair<string, int>>> room;

int main(){
  cin >> N >> M;

  for(int i = 0; i < N; i++){
    int a; string b; cin >> a >> b;
    bool flag = false;
    for(int j = 0; j < room.size(); j++){
      if(room[j].size() == M) continue;
      if(room[j][0].second - 10 <= a and room[j][0].second + 10 >= a){
        room[j].push_back({b, a});
        flag = !flag;
        break;
      }
    }
    if(!flag){
      room.push_back({{b, a}});
    }
  }

  for(int i = 0; i < room.size(); i++){
    sort(room[i].begin(), room[i].end());
    if(room[i].size() == M){
      cout << "Started!" << "\n";
      for(auto &j : room[i]){
        cout << j.second << " " << j.first << "\n";
      }
      continue;
    }
    cout << "Waiting!" << "\n";
    
    for(auto &j : room[i]){
      cout << j.second << " " << j.first << "\n";
    }
  }
}