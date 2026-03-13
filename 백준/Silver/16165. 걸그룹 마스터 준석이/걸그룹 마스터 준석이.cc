#include <bits/stdc++.h>

using namespace std;

map<string, vector<string>> group;
map<string, string> member;

int main(){
  int N, M; cin >> N >> M;
  
  while(N--){
    string team; cin >> team;
    int time; cin >> time;

    for(int i = 0; i < time; i++){
      string name; cin >> name;
      group[team].push_back(name);
      member[name] = team;
    }
  }

  while(M--){
    string name; int quiz; cin >> name >> quiz;

    if(quiz == 0) {
      sort(group[name].begin(), group[name].end());
      for(auto const &name : group[name]){
        cout << name << "\n";
      }
    }
    else {
      cout << member[name] << "\n";
    }
  }
}