#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int &cnt, int node, const vector<vector<int>> &graph, vector<int> &visited){
	
	for(auto i : graph[node]){
		if (visited[i] != 0) continue;
		visited[i] = cnt++;
		DFS(cnt, i, graph, visited);
	}
}

int main(){
	int N, M, R;
	
	cin >> N >> M >> R;
	
	vector<vector<int>> graph(N + 1);
	
	for (int i = 0; i < M; i++){
		int a, b;
		
		cin >> a >> b;
		
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	for (int i = 1; i < N + 1; i++){
		sort(graph[i].begin(), graph[i].end());
	}
	
	vector<int> visited(N + 1, 0);
	visited[R] = 1;
	
	int cnt = 2;
	
	DFS(cnt, R, graph, visited);
	
	for (int i = 1; i < N + 1; i++){
		cout << visited[i] << "\n";
	}
	
	cout << endl;
	
	return 0;
}