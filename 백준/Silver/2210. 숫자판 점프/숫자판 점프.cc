#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> board(5, vector<int>(5, 0));
int ans = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
set<int> s;

void DFS(int x, int y, int idx, int num){
  if(idx == 6){
    s.insert(num);
    return;
  }

  for(int next = 0; next < 4; next++){
    int nx = x + dx[next];
    int ny = y + dy[next];
    if(nx < 0 or nx >= 5 or ny < 0 or ny >= 5) continue;
    DFS(nx, ny, idx + 1, num * 10 + board[nx][ny]);
  }
}

int main(){
  
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      cin >> board[i][j];
    }
  }

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      DFS(i, j, 1, board[i][j]);
    }
  }

  cout << s.size();
}