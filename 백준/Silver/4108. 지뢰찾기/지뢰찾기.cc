#include <bits/stdc++.h>

using namespace std;

const vector<pair<int, int>> directions{{-1, -1}, {-1, 0}, {-1, 1},
{0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

void counting_mine(const vector<string> &board, int i, int j, vector<vector<char>> &answer, int N, int M){
	for(auto &next : directions){
		int nx = i + next.first;
		int ny = j + next.second;
		if(nx < 0 or nx >= N or ny < 0 or ny >= M) continue;
		if(board[nx][ny] != '.') continue;
		answer[nx][ny] = (answer[nx][ny] - '0' + 1) + '0';
	}
}

void check_mine(const vector<string> &board, vector<vector<char>> &answer, int N, int M){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(board[i][j] == '*') {
				answer[i][j] = '*';
				counting_mine(board, i, j, answer, N, M);	
			}
		}
	}
}

int main(){
	while(true){
		int N, M;
		cin >> N >> M;
		if(N == 0 and M == 0) break;
		
		vector<string> board(N);
		vector<vector<char>> answer(N, vector<char>(M, '0'));
		
		for(int i = 0; i < N; i++){
			cin >> board[i];
		}
		
		check_mine(board, answer, N, M);
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				cout << answer[i][j];
			}
			cout << endl;
		}
	}
}