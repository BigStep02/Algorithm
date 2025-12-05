#include <bits/stdc++.h>

using namespace std;

struct Point{
  int x;
  int y;
};

vector<Point> emptySpace;
vector<Point> teacher;
vector<Point> emptySpaceCombi;
bool possible = false;

bool watch(vector<vector<char>> &board, int N, int x, int y){
    for(int i = x - 1; i >= 0; i--){
        if(board[i][y] == 'W') break;
        if(board[i][y] == 'S') return false;
    }
    for(int i = x + 1; i < N; i++){
        if(board[i][y] == 'W') break;
        if(board[i][y] == 'S') return false;
    }
    for(int j = y - 1; j >= 0; j--){
        if(board[x][j] == 'W') break;
        if(board[x][j] == 'S') return false;
    }
    for(int j = y + 1; j < N; j++){
        if(board[x][j] == 'W') break;
        if(board[x][j] == 'S') return false;
    }
    return true;
}

void back_track(vector<vector<char>> &board, int N, int idx, int depth){
  if(possible) return;

  if(emptySpaceCombi.size() == 3){
    for(int i = 0; i < emptySpaceCombi.size(); i++){
      board[emptySpaceCombi[i].x][emptySpaceCombi[i].y] = 'W';
    }
    
    bool ok = true;
    for(Point &p : teacher){
      if(!watch(board, N, p.x, p.y)){
        ok = false;
        break;
      }
    }

    possible = ok;

    for(int i = 0; i < emptySpaceCombi.size(); i++){
      board[emptySpaceCombi[i].x][emptySpaceCombi[i].y] = 'X';
    }
    return;
  }

  for(int i = idx; i < emptySpace.size(); i++){
    emptySpaceCombi.push_back(emptySpace[i]);
    back_track(board, N, i + 1, depth);
    emptySpaceCombi.pop_back();
  }
}

int main(){
  int N; cin >> N;
  vector<vector<char>> board(N, vector<char>(N));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> board[i][j];
      if(board[i][j] == 'X'){
        emptySpace.push_back({i, j});
      }
      else if(board[i][j] == 'T'){
        teacher.push_back({i, j});
      }
    }
  }

  back_track(board, N, 0, 0);

  cout << ((possible)? "YES" : "NO");
}