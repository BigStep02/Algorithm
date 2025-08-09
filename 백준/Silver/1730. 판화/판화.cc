#include <bits/stdc++.h>

using namespace std;

bool check(char code, const pair<int, int> &now, const vector<pair<int, int>> &directions, int N){
	pair<int, int> tmp;
	if (code == 'U'){
		tmp.first = now.first + directions[3].first;
		tmp.second = now.second + directions[3].second;
		if (tmp.first < 0 or tmp.first >= N or tmp.second < 0 or tmp.second >= N) return false;
		return true;
	}
	if (code == 'D'){
		tmp.first = now.first + directions[1].first;
		tmp.second = now.second + directions[1].second;
		if (tmp.first < 0 or tmp.first >= N or tmp.second < 0 or tmp.second >= N) return false;
		return true;
	}
	if (code == 'L'){
		tmp.first = now.first + directions[2].first;
		tmp.second = now.second + directions[2].second;
		if (tmp.first < 0 or tmp.first >= N or tmp.second < 0 or tmp.second >= N) return false;
		return true;
	}if (code == 'R'){
		tmp.first = now.first + directions[0].first;
		tmp.second = now.second + directions[0].second;
		if (tmp.first < 0 or tmp.first >= N or tmp.second < 0 or tmp.second >= N) return false;
		return true;
	}
}

void draw_picture(char code, const vector<pair<int, int>> &directions, vector<vector<char>> &board, pair<int, int> &now){
	if (code == 'U' or code == 'D'){
		if(board[now.first][now.second] == '.'){
			board[now.first][now.second] = '|';
		}
		else if(board[now.first][now.second] == '-'){
			board[now.first][now.second] = '+';
		}
		if (code == 'U'){
			now.first += directions[3].first;
			now.second += directions[3].second;
			if (board[now.first][now.second] == '.'){
				board[now.first][now.second] = '|';
			}
			else if(board[now.first][now.second] == '-'){
				board[now.first][now.second] = '+';
			}
		}
		else{
			now.first += directions[1].first;
			now.second += directions[1].second;
			if (board[now.first][now.second] == '.'){
				board[now.first][now.second] = '|';
			}
			else if(board[now.first][now.second] == '-'){
				board[now.first][now.second] = '+';
			}
		}
	}
	else if(code == 'L' or code == 'R'){
		if(board[now.first][now.second] == '.'){
			board[now.first][now.second] = '-';
			}
		else if(board[now.first][now.second] == '|'){
			board[now.first][now.second] = '+';
			}	
		if(code == 'L'){
			now.first += directions[2].first;
			now.second += directions[2].second;
			if(board[now.first][now.second] == '.'){
			board[now.first][now.second] = '-';
			}
			else if(board[now.first][now.second] == '|'){
				board[now.first][now.second] = '+';
			}
		}
		else{
			now.first += directions[0].first;
			now.second += directions[0].second;
			if(board[now.first][now.second] == '.'){
			board[now.first][now.second] = '-';
			}
			else if(board[now.first][now.second] == '|'){
				board[now.first][now.second] = '+';
			}
		}
	}
}

int main(){
	int N;
	cin >> N;
	
	vector<vector<char>> board(N, vector<char>(N, '.'));
	
	string code;
	cin >> code;
	
	vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	pair<int, int> now{0, 0};
	
	for(int i = 0; i < code.size(); i++){
		if(check(code[i], now ,directions, N)) draw_picture(code[i], directions, board, now);
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << board[i][j];
		}
		cout << endl;
	}
}