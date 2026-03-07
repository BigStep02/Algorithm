#include <bits/stdc++.h>

using namespace std;

int N, ans = 0;;
vector<vector<int>> baseball;
vector<int> isUsed(9);
vector<int> permu(9);

int check(){
  int score = 0;
  int idx = 0;

  for(int i = 0; i < N; i++){
    int outCnt = 0;
    int b1 = 0, b2 = 0, b3 = 0;

    while(outCnt < 3){
      int nowScore = baseball[i][permu[idx]];

      if(nowScore == 0) outCnt++;
      else if(nowScore == 1){
        score += b3;
        b3 = b2; b2 = b1; b1 = 1;
      }
      else if(nowScore == 2){
        score += (b3 + b2);
        b3 = b1; b2 = 1; b1 = 0;
      }
      else if(nowScore == 3){
        score += (b3 + b2 + b1);
        b3 = 1; b2 = 0; b1 = 0;
      }
      else{
        score += (b3 + b2 + b1 + 1);
        b3 = 0; b2 = 0; b1 = 0;
      }
      idx = (idx + 1) % 9;
    }
  }

  return score;
}

void back_track(int cnt){
  if(cnt == 9){
    ans = max(ans, check());
    return;
  }

  if (cnt == 3) {
      back_track(cnt + 1);
      return;
  }

  for(int i = 0; i < 9; i++){
    if(isUsed[i] != 0) continue;
    isUsed[i] = 1;
    permu[cnt] = i;
    back_track(cnt + 1);
    isUsed[i] = 0;
  }
}

int main(){
  cin >> N;
  baseball.resize(N, vector<int>(9, 0));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < 9; j++){
      cin >> baseball[i][j];
    }
  }

  permu[3] = 0;
  isUsed[0] = 1;

  back_track(0);

  cout << ans;
}