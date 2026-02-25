#include <bits/stdc++.h>

using namespace std;

struct score{
  string name;
  int kor;
  int eng;
  int math;

  bool operator<(const score &other) const{
    if(kor != other.kor) return kor > other.kor;
    if(eng != other.eng) return eng < other.eng;
    if(math != other.math) return math > other.math;
    return name < other.name;
  }

};


int main(){
  int N; cin >> N;

  vector<score> scores;

  for(int i = 0; i < N; i++){
    string a;
    int b, c, d;
    cin >> a >> b >> c >> d;
    scores.push_back({a, b, c, d});
  }

  sort(scores.begin(), scores.end());

  for(int i = 0; i < N; i++){
    cout << scores[i].name << "\n";
  }
}