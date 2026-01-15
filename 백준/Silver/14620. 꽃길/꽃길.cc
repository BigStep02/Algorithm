#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> board;
vector<vector<bool>> visited;
int ans = INT_MAX;

bool possible(int x, int y){
  if(visited[x + 1][y] == false and visited[x - 1][y] == false and visited[x][y + 1] == false and visited[x][y - 1] == false)
    return true;

  return false;
}

void plantFlower(int x, int y){
  visited[x][y] = true;
  visited[x + 1][y] = true;
  visited[x - 1][y] = true;
  visited[x][y + 1] = true;
  visited[x][y - 1] = true;
}

void unplantFlower(int x, int y){
  visited[x][y] = false;
  visited[x + 1][y] = false;
  visited[x - 1][y] = false;
  visited[x][y + 1] = false;
  visited[x][y - 1] = false;
}

int flowerCost(int x, int y){
  return board[x][y] + board[x + 1][y] + board[x - 1][y] + board[x][y + 1] + board[x][y - 1];
}

void backtrack(int cnt, int cost){
  if(cnt == 3){
    ans = min(cost, ans);
    return;
  }

  for(int i = 1; i < board.size() - 1; i++){
    for(int j = 1; j < board.size() - 1; j++){
      if(possible(i, j)){
        plantFlower(i, j);
        backtrack(cnt + 1, cost + flowerCost(i, j));
        unplantFlower(i, j);
      }
    }
  }
}

int main(){
  int N; cin >> N;

  board.resize(N, vector<int> (N, 0));
  visited.resize(N, vector<bool> (N, false));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> board[i][j];
    }
  }

  backtrack(0, 0);

  cout << ans;
}