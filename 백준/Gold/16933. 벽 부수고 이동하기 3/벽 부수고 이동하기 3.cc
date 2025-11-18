#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

struct Node{
	int X;
	int Y;
	int breakWall;
	int day;
	int dist;
};

int N, M, K;
int visited[1001][1001][11][2];

void BFS(const vector<string> &board, queue<Node> &q){
	while(!q.empty()){
		auto [x, y, wall, day, dist] = q.front();
		q.pop();
		
		if(x == N - 1 and y == M - 1){
			cout << dist + 1;
			return;
		}
		
		for(int next = 0; next < 4; next++){
			int nx = x + dx[next];
			int ny = y + dy[next];
			if(nx < 0 or nx >= N or ny < 0 or ny >= M) continue;
			
			if(board[nx][ny] == '0' and visited[nx][ny][wall][1 - day] == 0){
				visited[nx][ny][wall][1 - day] = 1;
				q.push({nx, ny, wall, 1 - day, dist + 1});
			}
			else if(board[nx][ny] == '1' and wall < K){
				if(day == 0 and visited[nx][ny][wall + 1][1 - day] == 0){
					visited[nx][ny][wall + 1][1 - day] = 1;
					q.push({nx, ny, wall + 1, 1 - day, dist + 1});
				}
				else if(day == 1 and visited[x][y][wall][1 - day] == 0){
					visited[x][y][wall][1 - day] = 1;
					q.push({x, y, wall, 1 - day, dist + 1});
				}
			}
		}
	}
	
	cout << -1;
}

int main(){
	
	cin >> N >> M >> K;
	
	vector<string> board(N, "");
	for(int i = 0; i < N; i++){
		cin >> board[i];
	}
	
	queue<Node> q;
	q.push({0, 0, 0, 0, 0});
	visited[0][0][0][0] = 1;
	
	BFS(board, q);
}