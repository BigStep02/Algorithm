#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> board(5, vector<int>(5, 0));

void backtrack(int x, int y, int cnt, int depth){
  if(x < 0 or x >= 5 or y < 0 or y >= 5 or board[x][y] == -1) return;

  if(board[x][y] == 1) cnt++;

  if(cnt >= 2 and depth <= 3){
    cout << 1;
    exit(0);
  }

  int temp = board[x][y];
  board[x][y] = -1;
  backtrack(x + 1, y, cnt, depth + 1);
  backtrack(x - 1, y, cnt, depth + 1);
  backtrack(x, y + 1, cnt, depth + 1);
  backtrack(x, y - 1, cnt, depth + 1);
  board[x][y] = temp;
}

int main(){
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      cin >> board[i][j];
    }
  }

  int x, y; cin >> x >> y;

  backtrack(x, y, 0, 0);

  cout << 0;
}