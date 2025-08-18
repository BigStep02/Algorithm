#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cin >> N;
	
	vector<int> score(N + 1, 0);
	for(int i = 0; i < N * (N - 1) / 2; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if(c == d){
			score[a]++;
			score[b]++;
			continue;
		}
		(c > d)? score[a] += 3 : score[b] += 3;
	}
	
	multimap<int, int, greater<int>> answer;
	
	for(int i = 1; i < N + 1; i++){
		answer.insert({score[i], i});
	}
	
	vector<int> rank(N + 1);
	int prevScore = -1, cnt = 0, curRank = 0;;
	for(auto &i : answer){
		cnt++;
		if(i.first != prevScore){
			curRank = cnt;
			prevScore = i.first;
		}
		rank[i.second] = curRank;
	}
	
	for(int i = 1; i < N + 1; i++){
		cout << rank[i] << "\n";
	}
}