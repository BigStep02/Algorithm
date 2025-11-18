#include <bits/stdc++.h>

using namespace std;

struct Node{
	int screen;
	int clip;
	int time;
};

void BFS(int S, queue<Node> &q, vector<vector<int>> &visited){
	while(!q.empty()){
		auto [s, c, t] = q.front();
		q.pop();
		
		if(s == S){
			cout << t;
			return;
		}
		
		if(visited[s][s] == 0){
			visited[s][s] = 1;
			q.push({s, s, t + 1});
		}
		
		if(c > 0 and s + c <= 1000 and visited[s + c][c] == 0){
			visited[s + c][c] = 1;
			q.push({s + c, c, t + 1});
		}
		
		if(s > 0 and visited[s - 1][c] == 0){
			visited[s - 1][c] = 1;
			q.push({s - 1, c, t + 1});
		}
	}
}

int main(){
	int S;
	cin >> S;
	
	queue<Node> q;
	vector<vector<int>> visited(1001, vector<int>(1001, 0));
	
	q.push({1, 0, 0});
	visited[1][0] = 1;
	BFS(S, q, visited);
}