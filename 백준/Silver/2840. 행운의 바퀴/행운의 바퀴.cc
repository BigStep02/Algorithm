#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<char> board;
vector<bool> alpa(26, false);

int main(){
  cin >> N >> K;

  board.resize(N, '?');
  
  int idx = 0;

  for(int i = 0; i < K; i++){
    int a; char b; cin >> a >> b;
    idx = (idx + a) % board.size();

    if (board[idx] != '?' && board[idx] != b) {
      cout << "!";
      return 0;
    }
        
    if (board[idx] == '?' && alpa[b - 'A']) {
      cout << "!";
      return 0;
    }

    board[idx] = b;
    alpa[b - 'A'] = true;
  }

  for (int i = 0; i < N; i++) {
    cout << board[(idx - i + N) % N];
  }
}