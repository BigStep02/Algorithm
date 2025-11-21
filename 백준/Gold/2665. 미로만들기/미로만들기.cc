#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

struct Node{
	int x;
	int y;
};

void BFS(const vector<string> &board, vector<vector<int>> &visited, deque<Node> &q, int N, int black_wall){
	while(!q.empty()){
		auto [x, y] = q.front();
		q.pop_front();
		
		for(int next = 0; next < 4; next++){
			int nx = x + dx[next];
			int ny = y + dy[next];
			if(nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
			
			int nextCost = visited[x][y] + (board[nx][ny] == '0');

			if(nextCost < visited[nx][ny]){
        visited[nx][ny] = nextCost;
        if(board[nx][ny] == '1'){
          q.push_back({nx, ny});
        } else {
          q.push_front({nx, ny});
        }
      }
		}
	}
	cout << visited[N - 1][N - 1];
}

int main(){
	int N;
	cin >> N;
	
	vector<string> board(N, "");
	
	int black_wall = 0;
	
	for(int i = 0; i < N; i++){
		cin >> board[i];
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(board[i][j] == '0') black_wall++;
		}
	}
	
	vector<vector<int>> visited(N, vector<int>(N, INT_MAX));
	
	visited[0][0] = 0;
	deque<Node> q;
	q.push_back({0, 0});
	
	BFS(board, visited, q, N, black_wall);
}
