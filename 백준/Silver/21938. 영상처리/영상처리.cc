#include <bits/stdc++.h>

using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void BFS(const vector<vector<int>> &board, vector<vector<int>> &visited, queue<pair<int, int>> &q, int N, int M){
	while(!q.empty()){
		auto [x, y] = q.front();
		q.pop();
		for(int next = 0; next < 4; next++){
			int nx = x + dx[next];
			int ny = y + dy[next];
			if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if(board[nx][ny] != 255 or visited[nx][ny] != 0) continue;
			visited[nx][ny] = visited[x][y] + 1;
			q.push({nx, ny});
		}
	}
}

int main(){
	int N, M;
	cin >> N >> M;
	
	vector<vector<int>> board(N, vector<int>(M, 0));
	
	for(int i = 0; i < N; i++){
		for(int j = 0 ; j < M; j++){
			int A, B, C;
			cin >> A >> B >> C;
			board[i][j] = (A + B + C) / 3;
		}
	}
	
	int K;
	cin >> K;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(board[i][j] >= K) board[i][j] = 255;
			else board[i][j] = 0;
		}
	}
	
	
	
	int cnt = 0;
	vector<vector<int>> visited(N, vector<int>(M, 0));
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(board[i][j] == 255 and visited[i][j] == 0){
				cnt++;
				queue<pair<int, int>> q;
				q.push({i, j});
				visited[i][j] = 1;
				BFS(board, visited, q, N, M);
			}
		}
	}
	
	cout << cnt;
}