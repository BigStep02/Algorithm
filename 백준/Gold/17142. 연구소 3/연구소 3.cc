#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int zeroCnt = 0;

struct Virus{
	int x;
	int y;
};

vector<Virus> viruses;
vector<Virus> virusCombi;

int BFS(const vector<vector<int>> &board, int N){
	vector<vector<int>> visited(N, vector<int>(N, -1));
	queue<Virus> q;
	
	for(int i = 0; i < virusCombi.size(); i++){
		q.push(virusCombi[i]);
		visited[virusCombi[i].x][virusCombi[i].y] = 0;
	}
	
	int spreadCnt = 0;
	int maxTime = 0;
	
	while(!q.empty()){
		auto [x, y] = q.front();
		q.pop();
		for(int next = 0; next < 4; next++){
			int nx = x + dx[next];
			int ny = y + dy[next];
			if(nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
			if(board[nx][ny] == 1 or visited[nx][ny] != -1) continue;
			visited[nx][ny] = visited[x][y] + 1;
			q.push({nx, ny});
			if(board[nx][ny] == 0){
				spreadCnt++;
				maxTime = max(maxTime, visited[nx][ny]);
			}
		}
	}
	
	if (spreadCnt == zeroCnt) return maxTime;
	else return INT_MAX;
}

int DFS(const vector<vector<int>> &board, int N, int M, int start, int depth){
	if(depth == M){
		return BFS(board, N);
	}
	
	if(start == viruses.size()) return INT_MAX;
	
	int ret = INT_MAX;
	
	virusCombi.push_back(viruses[start]);
	ret = min(ret, DFS(board, N, M, start + 1, depth + 1));
	virusCombi.pop_back();
	
	ret = min(ret, DFS(board, N, M, start + 1, depth));
	
	return ret;
}

int main(){
	int N, M;
	cin >> N >> M;
	
	vector<vector<int>> board(N, vector<int>(N, 0));
	

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> board[i][j];
			if(board[i][j] == 2){
				viruses.push_back({i, j});
			}
			if(board[i][j] == 0){
				zeroCnt++;
			}
		}
	}
	
	int answer = DFS(board, N, M, 0, 0);
	
	cout << ((answer == INT_MAX)? -1 : answer);
}