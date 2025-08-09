#include <bits/stdc++.h>

using namespace std;

int main(){
	int M, N;
	
	cin >> M >> N;
	
	vector<vector<int>> board(M, vector<int>(N, 0));
	vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};	
	pair<int, int> now{0, 0};
	board[now.first][now.second] = 1;
	int dc = 0, result = 0, cnt = 2;
	
	while(cnt <= M * N){
		now.first += directions[dc].first;
		now.second += directions[dc].second;
		
		if(now.first < 0 or now.first >= M or now.second < 0 or now.second >= N or board[now.first][now.second] != 0){
			result++;
			now.first -= directions[dc].first;
			now.second -= directions[dc].second;
			dc++;
			if (dc >= 4) dc -= 4;
			continue;
		}
		
		board[now.first][now.second] = cnt++;
	}
	
	cout << result;
	
	return 0;
}