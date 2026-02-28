#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> board(5, vector<int>(5, 0));

int check(){
  int line = 0;

  for(int i = 0; i < 5; i++){
    int cnt = 0;
    for(int j = 0; j < 5; j++){
      if(board[i][j] == 0) cnt++;
    }
    if(cnt == 5) line++;
  }

  for(int j = 0; j < 5; j++){
    int cnt = 0;
    for(int i = 0; i < 5; i++){
      if(board[i][j] == 0) cnt++;
    }
    if(cnt == 5) line++;
  }

  int d1 = 0;
  for(int i = 0; i < 5; i++){
    if(board[i][i] == 0) d1++;
  }
  if(d1 == 5) line++;

  int d2 = 0;
  for(int i = 0; i < 5; i++){
    if(board[i][4 - i] == 0) d2++;
  }
  if(d2 == 5) line++;

  return line;
}

int main(){
  

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      cin >> board[i][j];
    }
  }

  for(int i = 1; i <= 25; i++){
    int a; cin >> a;
    for(int x = 0; x < 5; x++){
      for(int y = 0; y < 5; y++){
        if(board[x][y] == a){
          board[x][y] = 0;
          if(check() >= 3){
            cout << i;
            return 0;
          }
        }
      }
    }
  }
}