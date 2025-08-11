#include <bits/stdc++.h>

using namespace std;

void check_rank(const vector<string> &board, vector<int> &answer, int R, int C){
	int rank = 1;
	for(int j = C - 2; j > 1; j--){
		bool is_diff = false;
		for(int i = 0; i < R; i++){
			if('1' <= board[i][j] or board[i][j] <= '9'){
				int tmp = board[i][j] - '0';
				if (answer[tmp] != 0) continue;
				answer[tmp] = rank;
				is_diff = true;
			}
		}
		if(is_diff) rank++;
	}
}

int main(){
	int R, C;
	cin >> R >> C;
	
	vector<string> board(R);
	
	for(int i = 0; i < R; i++){
		cin >> board[i];
	}
	
	vector<int> answer(10, 0);
	
	check_rank(board, answer, R, C);
	
	for(int i = 1; i < answer.size(); i++){
		cout << answer[i] << "\n";
	}
}