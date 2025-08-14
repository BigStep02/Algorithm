#include <bits/stdc++.h>

using namespace std;

int main(){
	int N, L, H;
	cin >> N >> L >> H;
	vector<int> score(N);
	
	for(int i = 0; i < N; i++){
		cin >> score[i];
	}
	
	sort(score.begin(), score.end());
	
	int plus = 0;
	for(int i = L; i < N - H; i++){
		plus += score[i];
	}
	
	double answer = static_cast<double>(plus) / (N - (L + H));
	
	cout << fixed << setprecision(15) << answer;
}