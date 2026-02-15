#include <bits/stdc++.h>

using namespace std;

int main(){
  int N; cin >> N;
  map<string, int> books;

  for(int i = 0; i < N; i++){
    string s; cin >> s;
    if(books.find(s) != books.end()){
      books[s]++;
    }
    else books[s] = 1;
  }

  auto it = max_element(books.begin(), books.end(),[](const pair<string, int> &a, const pair<string, int> &b){
    if(a.second != b.second){
      return a.second < b.second;
    }
    else{
      return a.first > b.first;
    }
    
  });

  cout << it->first;
}