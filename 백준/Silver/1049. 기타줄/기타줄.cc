#include <bits/stdc++.h>

using namespace std;

struct Lines{
  int six;
  int one;
};

int main(){
  int N, M; cin >> N >> M;
  int min_one = INT_MAX;
  int min_six = INT_MAX;

  vector<Lines> linePrice(M);
  
  for(int i = 0; i < M; i++){
    cin >> linePrice[i].six >> linePrice[i].one;
    if(linePrice[i].one < min_one) min_one = linePrice[i].one;
    if(linePrice[i].six < min_six) min_six = linePrice[i].six;
  }

  int cnt = 0;
  
  if(min_six <= (min_one * 6)){
    cnt += min_six * (N / 6);
    N -= 6 * (N / 6);
    if(N > 0){
      cnt += ((min_six < (min_one * N)? min_six : min_one * N));
    }
  }
  else cnt += min_one * N;

  cout << cnt;
}