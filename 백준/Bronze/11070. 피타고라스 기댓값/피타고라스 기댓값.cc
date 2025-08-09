#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

void check_teamValue(const vector<pair<int, int>> & teamScore, vector<double> &teamValue){
	for(int i = 1; i < teamValue.size(); i++){
		if (teamScore[i].first == 0 && teamScore[i].second == 0){
			teamValue[i] = 0;
			continue;
		}
		teamValue[i] = pow(teamScore[i].first, 2) / (pow(teamScore[i].first, 2) + pow(teamScore[i].second, 2));
	}
}

int main(){
	int T;
	cin >> T;
	
	for(int i = 0; i < T; i++){
		int N, M;
		cin >> N >> M;
		
		vector<pair<int, int>> teamScore(N + 1);
		vector<double> teamValue(N + 1, 999999999);
		
		for(int j = 0; j < M; j++){
			int a, b, p, q;
			cin >> a >> b >> p >> q;
			
			teamScore[a].first += p;
			teamScore[a].second += q;
			teamScore[b].first += q;
			teamScore[b].second += p;
		}
		
		check_teamValue(teamScore, teamValue);
		sort(teamValue.begin(), teamValue.end());
		
		cout << static_cast<int>(teamValue[N - 1] * 1000) << "\n" << static_cast<int>(teamValue[0] * 1000) << endl;
	}
}