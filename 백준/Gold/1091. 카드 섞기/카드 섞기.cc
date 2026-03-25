#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> togo;
vector<int> shupple;
vector<int> nextCard;

bool check(){
  for(int i = 0; i < N; i++){
    if(i % 3 != togo[nextCard[i]]) return false;
  }

  return true;
}

void mix(){
  vector<int> temp(N);

  for(int i = 0; i < N; i++){
    temp[shupple[i]] = nextCard[i];
  }

  nextCard = temp;
}

bool original(){
  for(int i = 0; i < N; i++){
    if(nextCard[i] != i) return false;
  }

  return true;
}

int main(){
  cin >> N;

  togo.resize(N);
  shupple.resize(N);
  nextCard.resize(N);

  for(int i = 0; i < N; i++) cin >> togo[i];
  for(int i = 0; i < N; i++){
    cin >> shupple[i];
    nextCard[i] = i;
  } 

  int cnt = 0;

  while(true){
    if(check()){
      cout << cnt;
      return 0;
    }

    cnt++;
    mix();

    if(original()){
      cout << -1;
      return 0;
    }
  }
}