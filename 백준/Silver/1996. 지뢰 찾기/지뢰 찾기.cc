#include <bits/stdc++.h>

using namespace std;

const vector<pair<int, int>> diretions{{-1, -1}, {-1, 0},{-1, 1},
{0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

void plus_mine(const vector<string> &board, int N, vector<vector<char>> &answer, int mine, int x, int y){
	for(auto &next : diretions){
		int nx = x + next.first;
		int ny = y + next.second;
		if (nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
		if (board[nx][ny] != '.' or answer[nx][ny] == 'M') continue;
		int tmp = answer[nx][ny] - '0' + mine;
		(tmp >= 10)? answer[nx][ny] = 'M' : answer[nx][ny] = tmp + '0';
	}
}

void check_num(const vector<string> &board, int N, vector<vector<char>> &answer){
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if('1' <= board[i][j] && board[i][j] <= '9'){
				answer[i][j] = '*';
				plus_mine(board, N, answer, board[i][j] - '0', i, j);
			}
		}
	}
}

int main(){
	int N;
	cin >> N;
	
	vector<vector<char>> answer(N, vector<char>(N, '0'));
	vector<string> board(N);
		
	for(int i = 0; i < N; i++){
		cin >> board[i];
	}
	
	check_num(board, N, answer);
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << answer[i][j];
		}
		cout << endl;
	}
	
	return 0;
}