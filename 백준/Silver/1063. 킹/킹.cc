#include <bits/stdc++.h>

using namespace std;

string kingPos, stonePos;
int N;
vector<vector<int>> board(8, vector<int>(8, 0));
map<string, pair<int, int>> dir = {
    {"R", {1, 0}}, {"L", {-1, 0}}, {"B", {0, -1}}, {"T", {0, 1}},
    {"RT", {1, 1}}, {"LT", {-1, 1}}, {"RB", {1, -1}}, {"LB", {-1, -1}}
};
int main(){
  cin >> kingPos >> stonePos >> N;

  for(int i = 0; i < N; i++){
    string next; cin >> next;
    int kingX = kingPos[0] - 'A';
    int kingY = kingPos[1] - '1';
    int stoneX = stonePos[0] - 'A';
    int stoneY = stonePos[1] - '1';

    int kingnx = kingX + dir[next].first;
    int kingny = kingY + dir[next].second;
    
    if(kingnx < 0 or kingnx >= 8 or kingny < 0 or kingny >= 8) continue;
    if(kingnx == stoneX and kingny == stoneY){
      int stonenx = stoneX + dir[next].first;
      int stoneny = stoneY + dir[next].second;
      if(stonenx < 0 or stonenx >= 8 or stoneny < 0 or stoneny >= 8) continue;
      stonePos = { (char)(stonenx + 'A'), (char)(stoneny + '1') };
    }
    kingPos = { (char)(kingnx + 'A'), (char)(kingny + '1') };
  }

  cout << kingPos << "\n" << stonePos;
}