#include <bits/stdc++.h>

using namespace std;

struct Node{
  int x, y;
};

int N, M, ans = INT_MAX;
vector<vector<int>> board;
vector<Node> houses;
vector<Node> chickenHouses;
vector<int> chickenCombi;

int check_distance(){
  int total = 0;
  for(auto &i : houses){
    int mindist = INT_MAX;
    for(auto &j : chickenCombi){
      mindist = min(mindist, abs(i.x - chickenHouses[j].x) + abs(i.y - chickenHouses[j].y));
    }
    total += mindist;
  }

  return total;
}

void find_combi(int idx, int cnt){
  if(cnt == M){
    ans = min(ans, check_distance());
    return;
  }

  for(int i = idx; i < chickenHouses.size(); i++){
    chickenCombi.push_back(i);
    find_combi(i + 1, cnt + 1);
    chickenCombi.pop_back();
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> N >> M;

  board.resize(N, vector<int>(N, 0));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> board[i][j];
      if(board[i][j] == 1){
        houses.push_back({i, j});
      }
      if(board[i][j] == 2){
        chickenHouses.push_back({i, j});
      }
    }
  }

  find_combi(0, 0);

  cout << ans;
}