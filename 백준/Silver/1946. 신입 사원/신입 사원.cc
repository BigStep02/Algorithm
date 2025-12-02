#include <bits/stdc++.h>

using namespace std;

struct score{
  int first;
  int second;
};

bool operator<(const score &a, const score &b){
  if(a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}

int main(){
  int TestCase; cin >> TestCase;

  for(int i = 0; i < TestCase; i++){
    int N; cin >> N;
    vector<score> ps(N);
    for(int i = 0; i < N; i++){
      cin >> ps[i].first >> ps[i].second;
    }

    sort(ps.begin(), ps.end());

    int cnt = 1;
    int best = ps[0].second;
    for(int i = 1; i < N; i++){
      if(ps[i].second < best){
        cnt++;
        best = ps[i].second;
      }
    }

    cout << cnt << endl;
  }
}