#include <bits/stdc++.h>

using namespace std;

int main(){
  int N, M; cin >> N >> M;

  unordered_map<string, string> hsmap;

  for(int i = 0; i < N; i++){
    string s1, s2; cin >> s1 >> s2;
    hsmap[s1] = s2;
  }

  for(int i = 0; i < M; i++){
    string s; cin >> s;

    cout << hsmap[s] << "\n";
  }
}