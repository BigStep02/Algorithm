#include <bits/stdc++.h>

using namespace std;

int main(){
  int N; cin >> N;

  map<string, int> file;

  for(int i = 0; i < N; i++){
    string s; cin >> s;

    int idx = s.find_last_of('.');
    s = s.substr(idx + 1);

    file[s]++;
  }

  for(auto const &[key, value] : file){
    cout << key << " " << value << "\n";
  }
}