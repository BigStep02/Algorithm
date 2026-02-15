#include <bits/stdc++.h>

using namespace std;

int main(){
  int N; cin >> N;

  vector<int> switchState(N + 1);

  for(int i = 1; i <= N; i++){
    cin >> switchState[i];
  }

  int M; cin >> M;

  for(int i = 0; i < M; i++){
    int a, b; cin >> a >> b;
    if(a == 1){
      for(int i = b; i <= N; i += b) switchState[i] = (switchState[i] == 1) ? 0 : 1;
    }
    else{
      switchState[b] = (switchState[b] == 1) ? 0 : 1;
      int left = b - 1;
      int right = b + 1;
      while(left > 0 and right <= N){
        if(switchState[left] == switchState[right]){
          switchState[left] = (switchState[left] == 1) ? 0 : 1;
          switchState[right] = switchState[left];
          left--;
          right++;
        }
        else break;
      }
    }
  }

  for(int i = 1; i <= N; i++){
    cout << switchState[i] << " ";
    if(i % 20 == 0) cout << "\n";
  }
}