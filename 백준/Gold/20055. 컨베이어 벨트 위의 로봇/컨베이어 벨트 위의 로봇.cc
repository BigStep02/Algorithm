#include <bits/stdc++.h>

using namespace std;

int N, K, ans = 0, brokeCnt = 0;
vector<vector<int>> belt;
vector<bool> robot;

void rotation(){
  int btemp = belt[1][0];

  for(int i = 0; i < N - 1; i++){
    belt[1][i] = belt[1][i + 1];
  }
  belt[1][N - 1] = belt[0][N - 1];
  for(int i = N - 1; i > 0; i--){
    belt[0][i] = belt[0][i - 1];
    robot[i] = robot[i - 1];
  }
  if(robot[N - 1]) robot[N - 1] = false;
  robot[0] = false;
  belt[0][0] = btemp;
}

void robotMove(){
  for(int i = N - 1; i > 0; i--){
    if(!robot[i] and robot[i - 1] and belt[0][i] > 0){
      robot[i - 1] = false;
      robot[i] = true;
      belt[0][i]--;
      if(belt[0][i] <= 0) brokeCnt++;
    } 
  }
  if(robot[N - 1]) robot[N - 1] = false;
}

void upRobot(){
  if(belt[0][0] > 0){
    robot[0] = true;
    belt[0][0]--;
    if(belt[0][0] <= 0) brokeCnt++;
  }
}

int main(){
  cin >> N >> K;

  belt.resize(2, vector<int>(N, 0));
  robot.resize(N, false);

  for(int i = 0; i < N; i++) cin >> belt[0][i];
  for(int i = N - 1; i >= 0; i--) cin >> belt[1][i];


  while(brokeCnt < K){
    ans++;
    rotation();
    robotMove();
    upRobot();
  }

  cout << ans;
}