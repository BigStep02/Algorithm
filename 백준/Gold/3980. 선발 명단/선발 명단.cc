#include <bits/stdc++.h>

using namespace std;

int maxVal;
vector<vector<int>> board;
vector<bool> isUsed;

void back_track(int idx, int sum){
  if(idx == 11){
    maxVal = max(maxVal, sum);
    return;
  }

  for(int i = 0; i < 11; i++){
    if(isUsed[i] or board[idx][i] == 0) continue;
    isUsed[i] = true;
    back_track(idx + 1, sum + board[idx][i]);
    isUsed[i] = false;
  }
}

int main(){
  int tc; cin >> tc;

  while(tc--){
    board.assign(11, vector<int>(11, 0));
    isUsed.assign(11, false);
    maxVal = INT_MIN;

    for(int i = 0; i < 11; i++){
      for(int j = 0; j < 11; j++){
        cin >> board[i][j];
      }
    }

    back_track(0, 0);

    cout << maxVal << "\n";
  }
}