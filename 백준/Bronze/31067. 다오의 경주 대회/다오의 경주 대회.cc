#include <bits/stdc++.h>

using namespace std;

int main(){
	int N, K;
	cin >> N >> K;
	vector<int> track(N);
	int answer = 0;
	for(int i = 0; i < N; i++){
		cin >> track[i];
	}
	
	for(int i = 1; i < N; i++){
		if (track[i] <= track[i - 1]) {
			track[i] += K;
			answer++;	
		}
	}

	for(int i = 1; i < N; i++){
		if (track[i] <= track[i - 1]){
			cout << -1;
			return 0;
		}
	}
	
	cout << answer;
}