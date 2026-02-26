#include <bits/stdc++.h>

using namespace std;

int main(){
  string S;
  getline(cin, S);
  string word = "";

  stack<char> st;
  bool flag = false;

  for(int i = 0; i < S.size(); i++){
    if(S[i] == '<'){
      while(!st.empty()){
        word += st.top();
        st.pop();
      }
      flag = true;
      word += S[i];
      continue;
    }
    else if(S[i] == '>'){
      flag = false;
      word += S[i];
      continue;
    }
    if(flag) word += S[i];
    else{
      if(S[i] == ' '){
        while(!st.empty()){
          word += st.top();
          st.pop();
        }
        word += ' ';
      }
      else st.push(S[i]);
    }
  }

  while(!st.empty()){
    word += st.top();
    st.pop();
  }

  cout << word;
}