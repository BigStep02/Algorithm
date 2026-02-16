#include <bits/stdc++.h>

using namespace std;

int N, M;

int dist(int a, int b){
  //북쪽
  if(a == 1) return b;
  //동쪽
  else if(a == 4) return N + b;
  //남쪽
  else if(a == 2) return (2 * N) + M - b;
  //서쪽
  else return (2 * N) + (2 * M) - b;
}

int main(){
  cin >> N >> M;

  vector<int> board((N + M) * 2 + 1, 0);

  int store; cin >> store;
  int donggeun = 0;

  for(int i = 0; i < store + 1; i++){
    int a, b; cin >> a >> b;
    int temp = dist(a, b);
    if(i == store) donggeun = temp;
    else board[temp]++;
  }

  int ans = 0;

  for(int i = 0; i < board.size(); i++){
    if(board[i] > 0){
      int minDist = abs(i - donggeun);
      minDist = min(minDist, abs((N + M) * 2) - minDist) * board[i];
      ans += minDist;
    }
  }

  cout << ans;
}