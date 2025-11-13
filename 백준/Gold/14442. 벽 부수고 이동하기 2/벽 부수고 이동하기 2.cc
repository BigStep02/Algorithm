#include <bits/stdc++.h>

using namespace std;

struct Node{
	int x, y, broke;
};

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void BFS(const vector<string> &board, vector<vector<vector<int>>> &visited, queue<Node> &q, int N, int M, int K){
	while(!q.empty()){
		auto [x, y, broke] = q.front();
		q.pop();
		
		for(int next = 0; next < 4; next++){
			int nx = x + dx[next];
			int ny = y + dy[next];
			if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if(board[nx][ny] == '0' and visited[nx][ny][broke] == 0){
				visited[nx][ny][broke] = visited[x][y][broke] + 1;
				q.push({nx, ny, broke}); 
			}
			if(board[nx][ny] == '1' and broke < K and visited[nx][ny][broke + 1] == 0){
				visited[nx][ny][broke + 1] = visited[x][y][broke] + 1;
				q.push({nx, ny, broke + 1});
			}
		}
	}
}

int main(){
	int N, M, K;
	cin >> N >> M >> K;
	
	vector<string> board(N);
	
	for(int i = 0; i < N; i++){
		cin >> board[i];
	}
	
	vector<vector<vector<int>>> visited(N, vector<vector<int>>(M, vector<int>(K + 1, 0)));
	queue<Node> q;
	q.push({0, 0, 0});
	visited[0][0][0] = 1;
	
	BFS(board, visited, q, N, M, K);
	int min = INT_MAX;
	for(int i = 0; i <= K; i++){
		if(visited[N - 1][M - 1][i] < min and visited[N - 1][M - 1][i] != 0) min = visited[N - 1][M - 1][i];
	}
	
	cout << ((min == INT_MAX)? -1 : min);
}