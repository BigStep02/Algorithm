#include <bits/stdc++.h>

using namespace std;

int main(){
  int N, M; cin >> N >> M;

  vector<int> road(100);
  vector<int> yeon(100);

  int last = 0;

  for(int i = 0; i < N; i++){
    int end, speed; cin >> end >> speed;

    for(int j = last; j < last + end; j++){
      road[j] = speed;
    }

    last = last + end;
  }

  last = 0;

  for(int i = 0; i < N; i++){
    int end, speed; cin >> end >> speed;

    for(int j = last; j < last + end; j++){
      yeon[j] = speed;
    }

    last = last + end;
  }
  
  int maxVal = 0;

  for(int i = 0; i < 100; i++){
    if(road[i] < yeon[i]){
      maxVal = max(maxVal, yeon[i] - road[i]);
    }
  }

  cout << maxVal;
}