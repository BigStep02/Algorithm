#include <bits/stdc++.h>

using namespace std;

int main(){
  int N; cin >> N;

  int answer = N / 5 + ((N % 5 > 0)? 1 : 0);

  cout << answer;
}