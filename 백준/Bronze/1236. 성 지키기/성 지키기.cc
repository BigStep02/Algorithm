#include <bits/stdc++.h>

using namespace std;

bool check_line_count(int N, int M, int x, int y, vector<string> &board){
	for(int i = 0; i < N; i++){
		if (board[i][y] == 'X') return false;
	}
	for(int i = 0; i < M; i++){
		if (board[x][i] == 'X') return false;
	}
	
	return true;
}

int check_man(int N, int M, vector<string> &board){
	int cnt = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(board[i][j] != '.') continue;
			if(check_line_count(N, M, i, j, board)){
				board[i][j] = 'X';
				cnt++;	
			}
		}
	}
	return cnt;
}

bool last_x_check(int x, int M, vector<string> &board){
	for(int i = 0; i < M; i++){
		if(board[x][i] == 'X') return false;
	}
	return true;
}

bool last_y_check(int y, int N, vector<string> &board){
	for(int i = 0; i < N; i++){
		if(board[i][y] == 'X') return false;
	}
	return true;
}

int last_check(int N, int M, vector<string> &board){
	int cnt = 0;
	for(int i = 0; i < N; i++){
		if(last_x_check(i, M, board)) cnt++;
	}
	for(int i = 0; i < M; i++){
		if(last_y_check(i, N, board)) cnt++;
	}
	
	return cnt;
}

int main(){
	int N, M, answer = 0;
	cin >> N >> M;
	
	vector<string> board(N);
	
	for(int i = 0; i < N; i++){
		cin >> board[i];
	}
	
	answer += check_man(N, M, board);
	answer += last_check(N, M, board);

	cout << answer;
}