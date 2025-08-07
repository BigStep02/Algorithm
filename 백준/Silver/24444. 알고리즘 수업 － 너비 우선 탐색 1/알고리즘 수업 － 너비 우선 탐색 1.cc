#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

void BFS(vector<int> &visited, const vector<vector<int>> &graph, queue<int> &queue){
	int cnt = 2;
	while(queue.size() != 0){
		int node = queue.front();
		queue.pop();
		for (auto a : graph[node]){
			if (visited[a] != 0) continue;
			visited[a] = cnt++;
			queue.push(a);
		}
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
	
	queue<int> queue;
	
	queue.push(R);
	vector<int> visited(N + 1, 0);
	visited[R] = 1;
	
	BFS(visited, graph, queue);
	
	for (int i = 1; i < visited.size(); i++){
		cout << visited[i] << "\n";
	}
	
	cout << endl;
	
	return 0;
}