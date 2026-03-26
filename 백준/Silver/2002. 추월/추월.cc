#include <bits/stdc++.h>

using namespace std;

int N;
map<string, int> cars;
vector<int> out;

int main(){
  cin >> N;

  for(int i = 1; i <= N; i++){
    string a; cin >> a;
    cars[a] = i;
  }

  int cnt = 0;

  for(int i = 1; i <= N; i++){
    string a; cin >> a;
    out.push_back(cars[a]);
  }

  for(int i = 0; i < N - 1; i++){
    for(int j = i + 1; j < N; j++){
      if(out[i] > out[j]){
        cnt++;
        break;
      }
    }
  }

  cout << cnt;
}