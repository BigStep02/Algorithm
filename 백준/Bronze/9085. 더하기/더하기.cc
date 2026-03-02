#include <bits/stdc++.h>

using namespace std;

int main(){
  int testCase; cin >> testCase;

  while(testCase--){
    int a; cin >> a;
    int sum = 0;
    while(a--){
      int b; cin >> b;
      sum += b;
    }
    cout << sum << "\n";
  }
}