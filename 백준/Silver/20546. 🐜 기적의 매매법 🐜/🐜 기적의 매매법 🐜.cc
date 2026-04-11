#include <bits/stdc++.h>

using namespace std;

int main(){
  int N; cin >> N;

  int jun = N, sung = N;

  vector<int> price(14);

  for(int i = 0; i < 14; i++){
    cin >> price[i];
  }

  int sungGet = 0, junGet = 0, upCnt = 0, downCnt = 0;

  for(int i = 0; i < 14; i++){
    if(price[i] <= jun){
      junGet += jun / price[i];
      jun = jun % price[i];
    }
    if(i != 0 and price[i] > price[i - 1]){
      upCnt++;
      downCnt = 0;
    }
    if(i != 0 and price[i] < price[i - 1]){
      downCnt++;
      upCnt = 0;
    }
    if(i != 0 and price[i] == price[i - 1]){
      upCnt = 0;
      downCnt = 0;
    }

    if(upCnt >= 3){
      sung += sungGet * price[i];
      sungGet = 0;
    }
    if(downCnt >= 3){
      sungGet += sung / price[i];
      sung = sung % price[i];
    }
  }

  jun += junGet * price[13];
  sung += sungGet * price[13];

  if(jun < sung){
    cout << "TIMING";
  }
  else if(jun > sung){
    cout << "BNP";
  }
  else cout << "SAMESAME";
}