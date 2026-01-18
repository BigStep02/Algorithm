#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> word{1, 5, 10, 50};
vector<int> combiWord;
set<int> ansSet;

void backtrack(int idx, int sum){
  if(combiWord.size() == N){
    ansSet.insert(sum);
    return;
  }

  for(int i = idx; i < word.size(); i++){
    combiWord.push_back(word[i]);
    backtrack(i, sum + word[i]);
    combiWord.pop_back();
  }
}

int main(){
  cin >> N;

  backtrack(0, 0);

  cout << ansSet.size();
}