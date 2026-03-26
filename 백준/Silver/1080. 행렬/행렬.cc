#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<string> board;
vector<string> target;

void change(int x, int y){
  for(int i = x; i < x + 3; i++){
    for(int j = y; j < y + 3; j++){
      board[i][j] = (board[i][j] - '0') ^ 1 + '0';
    }
  }
}

int main(){
  cin >> N >> M;

  board.resize(N, string(M, 0));
  target.resize(N, string(M, 0));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> board[i][j];
    }
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> target[i][j];
    }
  }

  int cnt = 0;
  
  for(int i = 0; i < N - 2; i++){
    for(int j = 0; j < M - 2; j++){
      if(board[i][j] == target[i][j]) continue;
      cnt++;
      change(i, j);
    }
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(board[i][j] != target[i][j]){
        cout << -1;
        return 0;
      }
    }

  }

  cout << cnt;
}