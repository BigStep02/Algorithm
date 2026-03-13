#include <bits/stdc++.h>

using namespace std;

stack<pair<int, int>> tower;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N; cin >> N;

  for(int i = 1; i <= N; i++){
    int height; cin >> height;

    while(!tower.empty() and tower.top().first < height){
      tower.pop();
    }

    if(tower.empty()){
      cout << 0 << " ";
    }

    else{
      cout << tower.top().second << " ";
    }

    tower.push({height, i});
  }
}