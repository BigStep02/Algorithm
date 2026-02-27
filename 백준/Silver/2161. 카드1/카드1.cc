#include <bits/stdc++.h>

using namespace std;

int main(){
  int N; cin >> N;

  deque<int> dq;

  for(int i = 1; i <= N; i++){
    dq.push_back(i);
  }

  while(!dq.empty()){
    if(!dq.empty()){
      cout << dq.front() << " ";
      dq.pop_front();
    }
    if(!dq.empty()){
      dq.push_back(dq.front());
      dq.pop_front();
    }
  }
}