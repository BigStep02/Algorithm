#include <bits/stdc++.h>

using namespace std;

struct Node{
  int x;
  int y;
};

vector<Node> cur;
int answer = 0;

bool check(const vector<Node>& cur, int row, int col){
  for(const auto& queen : cur){
    if(queen.x == row || queen.y == col || abs(queen.x - row) == abs(queen.y - col)){
      return false;
    }
  }
  return true;
}

int BackTracking(int col, int N){
  if(col == N){
    answer++;
    return 0;
  }

  for(int i = 0; i < N; i++){
    if(check(cur, i, col)){
      cur.push_back({i, col});
      BackTracking(col + 1, N);
      cur.pop_back();
    }
  }
  return answer;
}

int main(){
  int N;
  cin >> N;

  cout << BackTracking(0, N);
}