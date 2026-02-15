#include <bits/stdc++.h>

using namespace std;

vector<string> chain(4);

void rotation(string &nowChain, int dir){
  if(dir == 1){
    int temp = nowChain[nowChain.size() - 1];
    for(int i = nowChain.size() - 1; i > 0; i--){
      nowChain[i] = nowChain[i - 1];
    }
    nowChain[0] = temp;
    return;
  }
  else{
    int temp = nowChain[0];
    for(int i = 0; i < nowChain.size() - 1; i++){
      nowChain[i] = nowChain[i + 1];
    }
    nowChain[nowChain.size() - 1] = temp;
    return;
  }
}

int main(){
  for(int i = 0; i < 4; i++){
    cin >> chain[i];
  }

  int N; cin >> N;
  for(int i = 0; i < N; i++){
    int a, b; cin >> a >> b;
    a--;
    vector<int> dirs(4, 0);
    dirs[a] = b;
    // 왼쪽으로 전파
    for(int i = a; i > 0; i--){
      if(chain[i][6] != chain[i - 1][2]){
        dirs[i - 1] = -dirs[i];
      }
      else break;
    }
    //오른쪽으로 전파
    for(int i = a; i < 3; i++){
      if(chain[i][2] != chain[i + 1][6]){
        dirs[i + 1] = -dirs[i];
      }
      else break;
    }

    for(int i = 0; i < 4; i++){
      if(dirs[i] == 0) continue;
      rotation(chain[i], dirs[i]);
    }
  }

  int ans = 0;
  if(chain[0][0] == '1') ans += 1;
  if(chain[1][0] == '1') ans += 2;
  if(chain[2][0] == '1') ans += 4;
  if(chain[3][0] == '1') ans += 8;

  cout << ans;
}