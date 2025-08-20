#include <bits/stdc++.h>

using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	
	vector<pair<int, int>> plant(N + 1, {-1, -1});
	
	for(int i = 0; i < M; i++){
		int a, c;
		char b;
		cin >> a >> b >> c;
		
		if(b == 'P'){
			plant[a].first = c;
		}
		if(b == 'M'){
			plant[a].second = c;
		}
	}

	int minCnt = 0, maxCnt = 0;
	
	for(int i = 1; i < plant.size(); i++){
		if(plant[i].first == 1 and plant[i].second == -1) maxCnt++;
		if(plant[i].first == -1 and plant[i].second == 0) maxCnt++;
		if(plant[i].first == -1 and plant[i].second == -1) maxCnt++;
		if(plant[i].first == 1 and plant[i].second == 0){
			minCnt++;
			maxCnt++;
		} 
	}
	
	cout << minCnt << " " << maxCnt;
}