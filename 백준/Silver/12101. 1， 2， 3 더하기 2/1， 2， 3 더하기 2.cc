#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

void backtrack(int N, int M, string word, int now){
  if(now > N) return;

  if(now == N){
    cnt++;
    if(cnt == M){
      cout << word << endl;
      exit(0);
    }
    return;
  }

  if (word.empty()) {
        backtrack(N, M, "1", now + 1);
        backtrack(N, M, "2", now + 2);
        backtrack(N, M, "3", now + 3);
    } else {
        backtrack(N, M, word + "+1", now + 1);
        backtrack(N, M, word + "+2", now + 2);
        backtrack(N, M, word + "+3", now + 3);
    }
}

int main(){
  int N, M; cin >> N >> M;
  
  backtrack(N, M, "", 0);

  cout << -1 << endl;
}