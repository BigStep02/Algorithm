#include <bits/stdc++.h>

using namespace std;

vector<bool> used;
vector<char> permuWord;
bool found = false;

void back_track(string &word, int N, int depth, int size, int &cnt){
  if(found) return;

  if(depth == size){
    cnt++;
    if(cnt == N){
      found = true;
      cout << word << " " << N << " = ";
      for(int i = 0; i < permuWord.size(); i++){
        cout << permuWord[i];
      }
      cout << endl;
    }
    return;
  }

  for(int i = 0; i < word.size(); i++){
    if(used[i]) continue;
    if(i > 0 && word[i] == word[i-1] && !used[i-1]) continue;
    permuWord.push_back(word[i]);
    used[i] = true;
    back_track(word, N, depth + 1, size, cnt);
    permuWord.pop_back();
    used[i] = false;
  }
}

int main(){
  string word;
  int N;

  while(cin >> word >> N){
    sort(word.begin(), word.end());
    int cnt = 0;
    used.assign(word.size(), false);
    permuWord.clear();
    found = false;

    back_track(word, N, 0, word.size(), cnt);
      
      
    if(!found) cout << word << " " << N << " = " << "No permutation" << endl;
  }
}
