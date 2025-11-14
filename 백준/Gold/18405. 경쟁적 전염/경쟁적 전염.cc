#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

class Virus{
	public:
		int type;
		int x, y;
		int time;
		
		Virus(int type, int x, int y, int time)
			:type(type), x(x), y(y), time(time) {}
};

class Laboratory{
	private:
		int N, K;
		vector<vector<int>> board;
		queue<Virus> q;
	
	public:
		Laboratory(int N, int K) :N(N), K(K) {
			board.assign(N, vector<int>(N, 0));
		}
		
		void initBoard(){
			vector<Virus> viruses;
			
			for(int i = 0; i < N; i++){
				for(int j = 0; j < N; j++){
					cin >> board[i][j];
					if(board[i][j] != 0){
						viruses.push_back(Virus(board[i][j], i, j, 0));
					}
				}
			}
			
			sort(viruses.begin(), viruses.end(),
			[](const Virus &a, const Virus &b){
				return a.type < b.type;
			});
			
			for(auto &x : viruses) q.push(x);
		}
		
		int spread(int S, int X, int Y){
			while(!q.empty()){
				Virus nowVirus = q.front();
				q.pop();
				
				if(nowVirus.time == S) break;
				
				for(int next = 0; next < 4; next++){
					int nx = nowVirus.x + dx[next];
					int ny = nowVirus.y + dy[next];
					if(nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
					if(board[nx][ny] != 0) continue;
					board[nx][ny] = nowVirus.type;
					q.push(Virus(nowVirus.type, nx, ny, nowVirus.time + 1));
				}
			}
			
			return board[X - 1][Y - 1];
		}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, K;
	cin >> N >> K;
	
	Laboratory lab(N, K);
	lab.initBoard();
	
	int S, X, Y;
	cin >> S >> X >> Y;
	cout << lab.spread(S, X, Y);
}