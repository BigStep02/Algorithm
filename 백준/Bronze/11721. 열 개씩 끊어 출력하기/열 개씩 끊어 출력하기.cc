#include <bits/stdc++.h>

using namespace std;

int main(){
  string s; cin >> s;

  string temp = "";

  for(int i = 0; i < s.size(); i++){
    temp += s[i];
    if(temp.size() == 10){
      cout << temp << "\n";
      temp = "";
    }
  }

  if(temp.size() >= 1){
    cout << temp;
  }
}