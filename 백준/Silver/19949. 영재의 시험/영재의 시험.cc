#include <bits/stdc++.h>

using namespace std;

vector<int> answer(10, 0);
vector<int> myAnswer;
int ans = 0;

bool check(){
  int tmp = 0;
  for(int i = 0; i < answer.size(); i++){
    if(answer[i] == myAnswer[i]) tmp++;
  }

  return tmp >= 5;
}

void backtrack(int prev, int cnt){
  if(answer.size() == myAnswer.size()){
    if(check()) ans++;
    return;
  }
  
  for(int i = 1; i <= 5; i++){
    if(i == prev and cnt == 2) continue;
    myAnswer.push_back(i);
    if(i == prev) backtrack(i, cnt + 1);
    else backtrack(i, 1);
    myAnswer.pop_back();
  }
}

int main(){
  for(int i = 0; i < answer.size(); i++){
    cin >> answer[i];
  }

  backtrack(-1, 0);

  cout << ans;
}