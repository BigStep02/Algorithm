#include <bits/stdc++.h>

using namespace std;

int main(){
  string word;


  while(true){
    int cnt = 0;
    getline(cin, word);
    if(word == "#") break;
    for(const auto &i : word){
      if(i == 'a' or i == 'A' or i == 'e' or i == 'E' or i == 'i' or i == 'I' or i == 'o' or i == 'O' or i == 'u' or i == 'U'){
        cnt++;
      }
    }
    cout << cnt << "\n";
  } 
}