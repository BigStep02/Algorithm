#include <bits/stdc++.h>

using namespace std;

int main(){
  string startG, endG, endS;
  cin >> startG >> endG >> endS;

  map<string, pair<bool, bool>> chat;

  int ans = 0;

  while(true){
    string a, b; cin >> a >> b;
    if(cin.eof()) break;
    if(a <= startG) chat[b].first = true;
    if(a >= endG and a <= endS) chat[b].second = true;
  }

  for(const auto & [name, check] : chat){
    if(check.first and check.second) ans++;
  }

  cout << ans;
}