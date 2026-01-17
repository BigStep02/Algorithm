#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> nums;
vector<vector<int>> prefixSum;

int main(){
  cin >> N >> M;

  nums.resize(N + 1, vector<int>(M + 1, 0));
  prefixSum.resize(N + 1, vector<int>(M + 1, 0));
  
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++){
      cin >> nums[i][j];
      prefixSum[i][j] =
        nums[i][j] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
    }
  }

  int K; cin >> K;

  for(int i = 0; i < K; i++){
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    cout << prefixSum[x2][y2] - prefixSum[x1 - 1][y2] - prefixSum[x2][y1 - 1] + prefixSum[x1 - 1][y1 - 1] << "\n";
  }
}