#include <bits/stdc++.h>

using namespace std;

int main(){
  int N; cin >> N;

  vector<pair<int,int>> line(6);
  
  int bigSizeW = 0;
  int bWIndex = 0;
  int bigSizeL = 0;
  int bLIndex = 0;

  for(int i = 0; i < 6; i++){
    cin >> line[i].first >> line[i].second;
    if(line[i].first == 1 or line[i].first == 2){
      bWIndex = (bigSizeW > line[i].second) ? bWIndex : i;
      bigSizeW = max(bigSizeW, line[i].second);
    }
    else{
      bLIndex = (bigSizeL > line[i].second) ? bLIndex : i;
      bigSizeL = max(bigSizeL, line[i].second);
    }
  }

  int smallSizeW = abs(line[(bLIndex + 5) % 6].second - line[(bLIndex + 1) % 6].second);
  int smallSizeL = abs(line[(bWIndex + 5) % 6].second - line[(bWIndex + 1) % 6].second);

  int bigSize = bigSizeL * bigSizeW;
  int smallSize = smallSizeL * smallSizeW;

  cout << (bigSize - smallSize) * N;
}