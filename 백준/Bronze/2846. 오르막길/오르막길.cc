#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cin >> N;
	
	vector<int> board(N);
	
	for(int i = 0; i < N; i++){
		cin >> board[i];
	}
	
	int maxCnt = 0, nowCnt = 0;
	for(int i = 1; i < N; i++){
		if (board[i] > board[i - 1]){
			nowCnt += board[i] - board[i - 1];
			continue;
		}
		if (maxCnt < nowCnt){
			maxCnt = nowCnt;
		}
		nowCnt = 0;
	}
	
	if (maxCnt < nowCnt){
		maxCnt = nowCnt;
		nowCnt = 0;
	}
	
	cout << maxCnt;
}