#include <bits/stdc++.h>

using namespace std;

bool check(int mid, const vector<int>& snack, int N, int M){
  int cnt = 0;
  for(int i = 0; i < M; i++){
    cnt += snack[i] / mid;
  }
  return cnt >= N;
}

int BinarySearch(const vector<int>& snack, int N, int M) {
  int answer = 0;
  int left = 1;
  int right = *max_element(snack.begin(), snack.end());
  while(left <= right){
    int mid = (left + right) / 2;
    if(check(mid, snack, N, M)){
      left = mid + 1;
      answer = mid;
    } else {
      right = mid - 1;
    }
  }
  
  return answer;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;
  vector<int> snack(M, 0);

  for(int i = 0; i < M; i++){
    cin >> snack[i];
  }

  cout << BinarySearch(snack, N, M);
}
